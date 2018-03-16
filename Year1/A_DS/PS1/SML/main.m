val zero = IntInf.fromInt 0;
val one = IntInf.fromInt 1;

fun gcd(a, b) = if a = zero then IntInf.toString b 
		else if b = zero then IntInf.toString b
		else if a = one orelse b = one then IntInf.toString one
		else if a < b then gcd(b mod a, a)(*Better to use modulo, it avoids successive subtractions*)
		else if b < a then gcd(a mod b, b)
		else IntInf.toString a;
