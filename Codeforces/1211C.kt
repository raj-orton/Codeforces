import java.util.*;
val scan = Scanner(System.`in`);
val N = 1000006;
 
fun main() {
	var n: Long = scan.nextLong();
	var k: Long = scan.nextLong();
	var cost: Long = 0L;
	var map = LongArray(N);
	for(i in 0..n - 1) {
		var a: Long = scan.nextLong();
		var b: Long = scan.nextLong();
		var p: Long = scan.nextLong();
		k = k - a;
		cost = cost + (a * p);
		if(b > a) {
			map[p.toInt()] += b - a;
		}
	}
	if(k < 0) {
		println("-1");
		return;
	}
	for(i in 1..N - 1) {
		var can: Long = Math.min(k, map[i]);
		k -= can;
		cost += (i * can);
		if(k == 0L) {
			break;
		}
	}
	if(k != 0L) {
		println("-1");
	}
	else {
		println(cost);
	}
}
