//Minimum Number Of Operations To Convert Time. 
class Solution0{
	const int MX_TIME = 24 * 60;
public:
	int convertTime(string current, string correct) {
		int hours = current[0] * 10 + current[1];
		int mins = current[3] * 10 + current[4];
		int abs0 = hours * 60 + mins, abs1;
		hours = correct[0] * 10 + correct[1];
		mins = correct[3] * 10 + correct[4];
		abs1 = hours * 60 + mins;
		int diff = (abs1 - abs0) % MX_TIME;
		if (diff < 0)diff += MX_TIME;
		return ((diff / 60) + ((diff % 60) / 15) + ((diff%60)%15)/5 + ((diff%60)%15)%5);
	}
};