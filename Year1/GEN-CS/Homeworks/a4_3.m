fun check(v, nil) = false
	|check(v, ls) = 
		if v = hd(ls) then
			true
		else check(v, tl(ls))

fun remove_duplicates(nil) = nil
	|remove_duplicates(ls) = 
		let val x = remove_duplicates(List.take(ls, length(ls)-1)) in
			if check(List.last(ls), x) then
				x
			else x@[List.last(ls)]
		end