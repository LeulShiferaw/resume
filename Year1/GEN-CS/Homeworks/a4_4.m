val phi = (1.0+Math.sqrt(5.0))/2.0;
val phi_hat = (1.0-Math.sqrt(5.0))/2.0;
val square = (fn x:real => x*x);

(*Fast exponentiation*)
(*b^e = (b^(e/2))^2 or b^e = b x (b^(e-1)/2))^2*)
(*Returns a tuple (a^e, b^e)*)
fun fast_exp(_, _, 0) = (1.0, 1.0) |
	fast_exp(a:real, b:real, e:int) = 
		if e mod 2 = 0 then 
			let val (x, y) = fast_exp(a, b, e div 2) in 
				(x*x, y*y) 
			end 
		else 
			let val (x, y) = fast_exp(a, b, (e-1) div 2) in 
				(a*x*x, b*y*y) 
			end;

(*Fn = phi^n - phi_hat^n / sqrt(5.0)*)
fun fib(n) = 
	let val (x, y) = fast_exp(phi, phi_hat, n) in 
		round((x - y) / Math.sqrt(5.0)) 
	end;

fun is_fib2(f1, f_n, n) = if f_n = n then (0, 0, true) else if f_n > n then (0, 0, false) else is_fib2(f_n, f_n + f1, n);
fun is_fib(n) = let val (_, _, x) = is_fib2(1, 1, n) in x end;