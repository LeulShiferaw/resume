datatype boolexp = zero | one |
				plus of boolexp * boolexp |
				times of boolexp * boolexp |
				compl of boolexp |
				var of int;

(*A list of the number section of all variables*)
fun var_list(zero) = nil |
	var_list(one) = nil |
	var_list(var(x)) = [x] |
	var_list(plus(x, y)) = var_list(x) @ var_list(y) |
	var_list(times(x, y)) = var_list(x) @ var_list(y) |
	var_list(compl(x)) = var_list(x);

fun exists(_, nil) = false |
	exists(x, ls) = if hd(ls) = x then true else exists(x, tl(ls));

(*Remove duplicates of x in ls*)
fun rd(_, nil) = nil |
	rd(x, ls) = if hd(ls) = x then rd(x, tl(ls))
				else hd(ls)::rd(x, tl(ls));

(*Removes duplicates of ls*)
fun rd_ls(nil) = nil |
	rd_ls(ls) = hd(ls)::rd_ls(rd(hd(ls), tl(ls)));

(*Add x to every element of ls*)
fun add(x, nil) = nil |
	add(x, ls) = (x::hd(ls))::add(x, tl(ls));

(*Generate an n-bit truth table*)
fun generate_tt(n) = if n = 0 then [[]]
				     else 
				     	let val x = generate_tt(n-1) in
				     		add(1, x) @ add(0, x)
				        end;

(*Make a tuple of elements of ls1 bound to elements of ls2*)
fun assign(nil, nil) = nil |
	assign(ls1, ls2) = (hd(ls1), hd(ls2))::assign(tl(ls1), tl(ls2));

(*When ls2 is a list of lists*)
fun assign_ls(_, nil) = nil |
	assign_ls(ls1, ls2) = assign(ls1, hd(ls2))::assign_ls(ls1, tl(ls2));

(*Indexing in a list of tuples*)
fun value(x, (a, b)::ls) = if x = a then b
						   else value(x, ls);

fun truth(1) = true |
	truth(0) = false;

(*Calculates the resulting truth value of the variable assignment array
  and the function*)
fun calc(_, one) = true |
	calc(_, zero) = false |
	calc(v_asign, var(x)) = truth(value(x, v_asign)) |
	calc(v_asign, compl(x)) = not (calc(v_asign, x)) |
	calc(v_asign, plus(x, y)) = if calc(v_asign, x) then true
						  else calc(v_asign, y) |
	calc(v_asign, times(x, y)) = if not (calc(v_asign, x)) then false
						   else calc(v_asign, y);

(*Satisfiable prime*)
(*If one can be true then satisfiable*)
fun satisfiable_p(nil, _) = false |
	satisfiable_p(v_asign, x) = if calc(hd(v_asign), x) then true else satisfiable_p(tl(v_asign) ,x);

fun satisfiable(x) =  let val vl = rd_ls(var_list(x)); val va = assign_ls(vl, generate_tt(length(vl))) in 
					if satisfiable_p(va, x) then 1 else 0
				end;

(*Falsifiable prime*)
(*If one can be false then true*)
fun falsifiable_p(nil, _) = false |
	falsifiable_p(v_asign, x) = if not(calc(hd(v_asign), x)) then true else falsifiable_p(tl(v_asign) ,x);

fun falsifiable(x) =  let val vl = rd_ls(var_list(x)); val va = assign_ls(vl, generate_tt(length(vl))) in 
					if falsifiable_p(va, x) then 1 else 0
				end;
(*Not falsifiable*)
fun valid(x) = 1 - falsifiable(x);

(*Not satisfiable*)
fun unsatisfiable(x) = 1 - satisfiable(x);