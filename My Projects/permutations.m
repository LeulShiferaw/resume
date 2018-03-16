fun add_pos(c, nil, _, _) = [c] |	
	add_pos(c, ls, i, n) = if i = n then c::ls else add_pos(c, tl(ls), i+1, n);

fun add_everywhere(c, nil, i) = add_pos(c, ls, i, List.leng) |
	add_everywhere(c, ls, i) = add_pos(c, ls, i, List.length(ls))::add_everywhere(c, ls, i+1);

fun add_everywhere_lls(c, nil) = nil |
	add_everywhere_lls(c, ls) = add_everywhere(c, hd(ls))::add_everywhere_lls(c, tl(ls));
