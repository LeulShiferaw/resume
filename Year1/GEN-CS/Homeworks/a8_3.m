(*Apply QMC1 on list ls*)
fun QMC1(ls, i) = let 
					(*Puts c on different elements*)
					fun rem_diff(nil, nil, _) = nil |
						rem_diff(ls1, ls2, c) = if not (length(ls1) = length(ls2)) then nil
												 else if hd(ls1) = hd(ls2) then hd(ls1)::rem_diff(tl(ls1), tl(ls2), c)
												 else c::rem_diff(tl(ls1), tl(ls2), c);

					(*number of elements is ls that match to n*)
					fun num(_, nil) = 0 |
						num(n, ls) = if hd(ls) = n then num(n, tl(ls))+1
									 else num(n, tl(ls));

					(*Takes one row and a table*)
					(*It applies one step of QMC1 on all the rows of the table*)
					fun qmc1(_, nil) = nil |
						qmc1(ls1, ls2) = let val x = rem_diff(ls1, hd(ls2), 2); val y = rem_diff(ls1, hd(ls2), 3) in
											 if not(num(3, y) = 1) then 
												qmc1(ls1, tl(ls2))
											 else x::qmc1(ls1, tl(ls2))
										 end;

					(*Does qmc on the whole list*)
					fun qmc1_ls(ls, i) =    if i >= length(ls) then nil else 
												let val x = qmc1(List.nth(ls, i), (List.take(ls, i) @ List.drop(ls, i+1))) in (*Perform QMC on the list after we remove the current element*)
													if x = nil then 
														List.nth(ls, i)::qmc1_ls(ls, i+1)
													else x @ qmc1_ls(ls, i+1)
												end;
					(*Compares 2 lists*)
					fun equal(nil, nil) = true |
						equal(ls1, ls2) = if hd(ls1) = hd(ls2) then equal(tl(ls1), tl(ls2)) 
										  else false;

					(*Compares 2 tables*)
					fun equal_ls(nil, nil) = true |
						equal_ls(ls1, ls2) = if not(length(ls1) = length(ls2)) then false 
						 					 else if equal(hd(ls1), hd(ls2)) then equal_ls(tl(ls1), tl(ls2))
											 else false;
					
					(*removes duplicates that matches to x*)
					fun rem_duplicate(_, nil) = nil |
						rem_duplicate(x, ls) = if equal(x, hd(ls)) then rem_duplicate(x, tl(ls))
											   else hd(ls)::rem_duplicate(x, tl(ls));

					(*Removes all duplicates in ls*)
					fun rem_duplicate_ls(nil) = nil |
						rem_duplicate_ls(ls) = hd(ls)::rem_duplicate_ls(rem_duplicate(hd(ls), tl(ls)));

					(*Proper qmc1*)
					(*It removes the duplicates*)
					fun p_qmc1(ls, i) = rem_duplicate_ls(qmc1_ls(ls, i));

					val x = p_qmc1(ls, i) 
				  in 
						   (*Repeat until there is no change*)
						   if equal_ls(x, ls) then ls 
						   else QMC1(x, 0)
				  end;

(*Perform qmc2 and qmc1 on a list of truth values ls*)
fun QMC2(ls) = let 
					fun truth(1) = true |
						truth(0) = false;

					(*Takes a truth val eg. FFFF and an element from the table after QMC1 and computes the result*)
					fun calc_tval(nil, _) = true |
						calc_tval(tv, f) = if hd(f) = 2 then
												calc_tval(tl(tv), tl(f))
											else if hd(f) = 1 then
												truth(hd(tv)) andalso calc_tval(tl(tv), tl(f))
											else not(truth(hd(tv))) andalso calc_tval(tl(tv), tl(f));
					
					(*One row of QMC2 table*)
					fun calc_tval_ls(nil, _) = nil |
						calc_tval_ls(tvs, f) = calc_tval(hd(tvs), f)::calc_tval_ls(tl(tvs), f);

					(*Makes the table for qmc2 by using the list of functions
					  and the list of the truth values*)
					fun qmc2_table(nil, _) = nil |
						qmc2_table(ls_f, ls_tv) = calc_tval_ls(ls_tv, hd(ls_f))::qmc2_table(tl(ls_f), ls_tv);
					
					(*Gives back the functions after non-essentials are removed*)
					fun qmc2(ls, ls_f : int list list, i) = if i >= length(ls) orelse ls = nil then nil else 
										  let 
										  	(*Transpose of a row matrx*)
										    fun transpose_row(nil) = nil |
												transpose_row(ls) = [hd(ls)]::transpose_row(tl(ls));

											(*Transpose of a matrix*)
											fun transpose(nil) = nil |
												transpose(a::nil) = transpose_row(a) |
												transpose(a::b) = 
													let 
														fun insert_row(nil, d) = d |
															insert_row(c, d) = ([hd(c)] @ hd(d))::insert_row(tl(c), tl(d))
													in 
														insert_row(a, transpose(b))
													end;

											(*Check if all elements in a list contain non true(1) values*)
											fun all_false(nil) = true |
												all_false(a::b) = if a then false else all_false(b);

											(*For is_col_essential and is_row_essential we have to assume the input has been transposed*)
											(*Checks if the ith row of the column list is essential*)
											fun is_col_essential(nil, _) =  false |
												is_col_essential(ls, i) = if all_false(List.take(ls, i) @ List.drop(ls, i+1)) andalso List.nth(ls, i) then true else false;

											(*Checks if the ith row of the list is essential*)
											fun is_row_essential(nil, _) = false |
												is_row_essential(ls_t, i) = if is_col_essential(hd(ls_t), i) then true else is_row_essential(tl(ls_t), i);
										  	val ls_t = transpose(ls) 
										  in 	
												if is_row_essential(ls_t, i) then 
													List.nth(ls_f, i)::qmc2(ls, ls_f, i+1)
												else qmc2((List.take(ls, i) @ List.drop(ls, i+1)), (List.take(ls_f, i) @ List.drop(ls_f, i+1)), i)
										  
										  end;
					val q1ls = QMC1(ls, 0) (*Apply QMC1 2 is used instead of X*)
				in 
					qmc2(qmc2_table(q1ls, ls), q1ls, 0)
				end;

fun QuineMcCulskey(ls) = 
	let
		(*Converts literal to the string form*)
		fun to_result(0, i) = implode((#"(")::(#"-")::(#"x")::chr(ord(#"0")+i)::(#")")::nil) |
			to_result(1, i) = implode((#"x")::chr(ord(#"0")+i)::nil);

		(*Converts monomials to string form*)
		fun to_result_ls(nil, _) = "" |
			to_result_ls(ls, i) = if hd(ls) = 2 then to_result_ls(tl(ls), i+1) 
								  else implode(explode(to_result(hd(ls), i)) @ explode(to_result_ls(tl(ls), i+1)));

		(*Converts combination of monomials to string form*)
		fun to_result_lls(nil) = "" |
			to_result_lls(ls) =  let val x = explode(to_result_lls(tl(ls))) in
									if length(x) = 0 then
										implode(explode(to_result_ls(hd(ls), 1)))
									else implode(explode(to_result_ls(hd(ls), 1)) @ explode(" + ") @ x)
								 end;

		(*Minimizes the input to the values that corresponde to true*)
		fun minimize(nil) = nil |
			minimize((a, b)::c) = if b = 1 then a::minimize(c) else minimize(c);
	in
		to_result_lls(QMC2(minimize(ls)))
	end;