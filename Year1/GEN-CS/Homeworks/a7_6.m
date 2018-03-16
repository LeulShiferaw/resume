(*Compares two strings and checks if a is a prefix of b*)
fun is_prefix(a, b) = 
		if  length(explode a) <= length(explode b) then 
			implode(List.take(explode b, length(explode a))) = a 
		else false;

(*Compares a string and a (char*string) list and checks if the string is a prefix of any of the string in the list*)
fun is_prefix_ls(_, nil) = false |
	is_prefix_ls(a, (_, b)::ls) = 
		if is_prefix(a, b) orelse is_prefix(b, a) then 
			true 
		else is_prefix_ls(a, ls);

(*Compares a char and a (char*string) list and checks if the char is equal to any of the chars in the list*)
fun exists(_, nil) = false |
	exists(a, (b, _)::ls) = 
		if a = b then 
			true 
		else exists(a, ls);

fun is_prefix_code(nil) = true |
	is_prefix_code(ls) = 
		let val (a, b) = hd(ls) in 
			if exists(a, tl(ls)) orelse is_prefix_ls(b, tl(ls)) then 
				false 
			else is_prefix_code(tl(ls)) 
		end;