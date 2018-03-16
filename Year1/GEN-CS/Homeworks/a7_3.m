exception err;

fun grep(pattern:string, in_file, out_file) = 
	let 
		val ins = TextIO.openIn in_file
		val outs = TextIO.openOut out_file
		fun helper(input_str) = 
			case input_str of 
				NONE => (TextIO.closeIn ins; TextIO.closeOut outs) |
				SOME str => if String.isSubstring pattern str then (TextIO.output(outs, str); helper(TextIO.inputLine ins)) else helper(TextIO.inputLine ins)
	in
		helper(TextIO.inputLine ins)
	end
