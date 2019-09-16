import java.util.*;
val scan = Scanner(System.`in`);
 
fun main() {
	var n: Long = scan.nextLong();
	var id: Long = -1;
	var max: Long = -1;
	for(i in 0..n - 1) {
		var x: Long = scan.nextLong();
		if(max <= x) {
			id = i;
			max = x;
		}
	}
	id = id + 1;
	var ans: Long = (n * max) - (n - id);
	println(ans);
}
