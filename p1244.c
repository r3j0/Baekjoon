//1244. 스위치 켜고 끄기
#include <stdio.h>

void onoff(int swt[], int index) {
	if (swt[index] == 0)
		swt[index] = 1;
	else
		swt[index] = 0;
}

int main(void) {
	int n;
	int swt[101] = {0,};
	
	int sn;
	int stu[101][2] = { 0, };

	int cnt = 0;

	int m_lap;
	int w_lap;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &swt[i]);

	scanf("%d", &sn);
	for (int i = 0; i < sn; i++)
		scanf("%d %d", &stu[i][0], &stu[i][1]);

	while (cnt != sn) {
		w_lap = 1;
		if (stu[cnt][0] == 1) {
			m_lap = stu[cnt][1] - 1;
			while (m_lap + 1 <= n) {
				onoff(swt, m_lap);
				m_lap += stu[cnt][1];
			}
		}
		else if (stu[cnt][0] == 2) {
			onoff(swt, stu[cnt][1] - 1);
			while (stu[cnt][1] - 1 - w_lap >= 0 && stu[cnt][1] - 1 + w_lap < n) {
				if (swt[stu[cnt][1] - 1 - w_lap] == swt[stu[cnt][1] - 1 + w_lap]) {
					onoff(swt, stu[cnt][1] - 1 - w_lap);
					onoff(swt, stu[cnt][1] - 1 + w_lap);
					w_lap++;
				}
				else
					break;
			}
		}
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", swt[i-1]);
		if (i%20 == 0)
			printf("\n");
	}
	return 0;
}