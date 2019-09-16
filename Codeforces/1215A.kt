import java.util.*;
val scan = Scanner(System.`in`);
 
fun main() {
	var n: Int = scan.nextInt();
	var map = mutableMapOf<Int, Int>();
	for(i in 0..n - 1) {
		var x: Int = scan.nextInt();
		map[x] = i + 1;
	}
	map = map.toSortedMap();
	var sz: Int = map.size;
	if(sz < 3) {
		println("-1 -1 -1");
	}
	else {
		var cnt: Int = 0;
		for((key, value) in map) {
		    if(cnt == 3) break;
		    print( "$value ");
		    cnt++;
		}
	}
}
