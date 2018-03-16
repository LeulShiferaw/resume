(*Alternating Sum*)
fun alternating(nil) = 0
	|alternating(a) = 
		hd(a)-alternating(tl(a));