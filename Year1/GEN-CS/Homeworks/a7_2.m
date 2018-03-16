exception NoSecEle;

fun max(nil) = raise NoSecEle |
	max(a::nil) = raise NoSecEle |
	max((a:real)::(b:real)::nil) = if Real.==(a, b) then raise NoSecEle else if a > b then b else a |
	max((a:real)::(b:real)::(c:real)::(ls:real list)) = if Real.==(a, b) then max(a::c::ls)
														else if Real.==(a, c) then max(a::b::ls)
														else if Real.==(b, c) then max(a::b::ls)
														else if a > b then 
															if a > c then 
																if c > b then max(a::c::ls) 
																else max(a::b::ls)
															else max(c::a::ls)
														else if a > c then max(b::a::ls)
														else if b > c then max(b::c::ls)
														else max(c::b::ls);