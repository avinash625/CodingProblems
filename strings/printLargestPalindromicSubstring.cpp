
void findLongestPalindromicString(char text[])
{
	int length = strlen(text);
	int result =  1;
	int maxLength = 1;
	int odd = 1;
	int left, right;
	for (int iter = 1; iter<length; iter++){
		left = iter - 1;
		right = iter + 1;
		odd = 1;
		while (left >= 0 && right<length && text[left] == text[right]){
			odd = odd + 2;
			left--;
			right++;
		}
		if (odd > maxLength){
			result = iter;
			maxLength = right - left-1;
		}
	}
	int even = 0;
	for (int iter = 0; iter<length - 1; iter++){
		if (text[iter] == text[iter + 1]){
			left = iter;
			right = iter + 1;
			while (text[left] == text[right] && left >= 0 && right < length){
				left--;
				right++;
			}
			if ((right - left-1) > maxLength){
				result = iter;
				maxLength = (right - left-1);
			}
		}
	}
	int start = (result - ((maxLength + 1) / 2)+1);
	int iter = 0;
	while (iter < maxLength){
		cout << text[start];
		start++;
		iter++;
	}
	cout << endl;
}