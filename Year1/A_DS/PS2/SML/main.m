val zero = IntInf.fromInt 0;
val one = IntInf.fromInt 1;

fun gcd(a, b) = if a = zero then b 
		else if b = zero then  b
		else if a = one orelse b = one then  one
		else if a < b then gcd(b mod a, a)(*Better to use modulo, it avoids successive subtractions*)
		else if b < a then gcd(a mod b, b)
		else a;

datatype rat=pair of IntInf.int * IntInf.int;

exception Error;(*e-must be a positive integer*)
fun equal(pair(a, b), pair(d, e)) = if not (b > 0) then raise Error else (a*e=b*d);

fun add(pair(a, b), pair(d, e)) = if not(b>0 andalso e>0) then raise Error else pair(IntInf.+(a*e, b*d), b*e);
fun addinv(pair(a, b)) = if not (b>0) then raise Error else pair(~1*a, b);

fun mult(pair(a, b), pair(d, e)) = if not(b>0 andalso e>0) then raise Error else pair(a*d, b*e);
fun multiv(pair(a, b)) = if not (b>0) then raise Error else pair(b, a);

fun normal(pair(a, b)) = if not (b>0) then raise Error else let val g= gcd(a, b) in
				pair(a div g, b div g)
			 end;
