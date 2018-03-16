exception neg;

fun H(0) = 0 |
	H(n) = if n < 0 then raise neg else n - H(H(H(n-1)));

fun Q(1) = 1 |
	Q(2) = 1 |
	Q(n) = if n < 0 then raise neg else Q(n-Q(n-1)) + Q(n-Q(n-2));

fun male(0) = 0 |
	male(n) = if n < 0 then raise neg else n-female(male(n-1)) 
and female(0) = 1 |
	female(n) = if n < 0 then raise neg else n - male(female(n-1));

fun a(0) = 1 |
	a(1) = 2 |
	a(n) = if n < 0 then raise neg else a(n-2) * Q(n+1);

fun b(0) = c(1) |
	b(1) = c(2) |
	b(n) = if n < 0 then raise neg else c(n-2)
and c(0) = 1 |
	c(n) = a(n-1)*c(n-1);

fun d(0) = 0 |
	d(n) = b(a(n));