datatype 'a LList = NIL | CONS of 'a * 'a LList;

 (*It s all automatically polymorphic*)
fun concat(NIL, b) = b
  | concat(a, NIL) = a
  | concat(CONS(a, b), c) = CONS(a, concat(b, c));

exception NOLAST;

fun last(NIL) = raise NOLAST
  | last(CONS(a, NIL)) = a
  | last(CONS(a, b: 'Z LList)) = last(b);

fun drop_last(NIL) = NIL
  | drop_last(CONS(a, NIL)) = NIL
  | drop_last(CONS(a, b)) = CONS(a, drop_last(b));

fun reverse(NIL) = NIL
  | reverse(a) = CONS(last(a), reverse(drop_last(a)));
