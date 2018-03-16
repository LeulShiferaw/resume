(*Gives back a sorted list from two sorted lists*)
fun merge(nil, a) = a |
	merge(a, nil) = a |
	merge(a, b) = if ord(hd(a)) < ord(hd(b)) then hd(a)::merge(tl(a), b) else hd(b)::merge(a, tl(b));

(*Invariant each half is always sorted*)
(*If merge is applied then result is also sorted*)
fun merge_sort(nil, _, _) = nil |
	merge_sort(ls, s, e) = if s+1 = e then [List.nth(ls, s)] else
								let val m = (s+e) div 2 in 
									merge(merge_sort(ls, s, m), merge_sort(ls, m, e))
								end;

fun are_anagrams(a, b) = 
	let val chr_a = explode a; val chr_b = explode b; val l_a = length chr_a; val l_b = length chr_b in
		if not (l_b = l_a) then false
		else if merge_sort(chr_a, 0, length(chr_a)) = merge_sort(chr_b, 0, length(chr_b)) then
			true
		else false
	end

(*Returns a tuple of two. One of them are the anagrams of s in ls and the other is the ls without the anagrams*)
fun find_remove_anagrams(s, nil) = (nil, nil) |
	find_remove_anagrams(s, ls) = 
		let val (x, y) = find_remove_anagrams(s, tl(ls)) in
			if are_anagrams(s, hd(ls)) then
				(hd(ls)::x, y)
			else (x, hd(ls)::y)
		end

fun listAnagrams(nil) = nil |
	listAnagrams(ls) = let val (x, y) = find_remove_anagrams(hd(ls), ls) in x::listAnagrams(y) end; (* x = anagrams of hd(ls) and y = ls without anagrams of hd(ls) *)