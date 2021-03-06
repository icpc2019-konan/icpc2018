//icpc2018 problemA Income Inequality
#include <stdio.h>

int main(void){
	while(1){
		//入力
		int n;
		scanf_s(" %d", &n);
		if(n==0) break;

		static int a[10001];
		for(int i=0; i<n; i++){
			scanf_s(" %d", &a[i]);
		}

		//処理
		double ave = 0.0;
		for(int i=0; i<n; i++){
			ave += a[i];
		}
		ave = ave/(double)n;

		int count = 0;
		for(int i=0; i<n; i++){
			if(a[i] <= ave) count++;
		}

		//出力
		printf("%d\n", count);
	}

	return 0;
}