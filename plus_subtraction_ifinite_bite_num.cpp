#include <stdio.h>
#include <string>
#include <iostream>
#include <io.h>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	string n1 = "5.275764315767345467345711111111111111111111111111111";
	string n2=  "9.64542187673346464573464871111111111111111111111111111111111111111111";
	int pose_n1 = n1.find(".");
	int pose_n2 = n2.find(".");

	string zhengshu_str_n1 = n1.substr(0, pose_n1);
	int zhengshu_int_n1 = atoi(zhengshu_str_n1.c_str());

	string zhengshu_str_n2 = n2.substr(0, pose_n2);
	int zhengshu_int_n2 = atoi(zhengshu_str_n2.c_str());

	int str_n1 = n1.length();
	int str_n2 = n2.length();
	int jinwei = 0;
	vector<int> out;
	if (str_n2 > str_n1) {

		for (int j = 0; j < str_n2 - str_n1; j++) {
			string more1 = n2.substr(str_n2 - j - 1, 1);
			int more = atoi(more1.c_str());
			out.push_back(more);
		}

		for (int i = 0; i < str_n1; i++) {
			string t1 = n1.substr(str_n1-i-1, 1);
			string t2 = n2.substr(str_n1 - i - 1, 1);
			if (t1 == "." || t2 == ".") {
				break;
			}
			else {
				int x1 = atoi(t1.c_str());
				int x2 = stoi(t2.c_str());
				int sum = x1 + x2 + jinwei;
				if (sum > 9) {
					jinwei = 1;
					sum = sum - 10;
					out.push_back(sum);
				}
				else {
					jinwei = 0;
					out.push_back(sum);
				}
			}
		}
	}
	else if (str_n1 > str_n2) {

		for (int j = 0; j < str_n1 - str_n2; j++) {

			string more1 = n1.substr(str_n1 - j - 1, 1);
			int more = atoi(more1.c_str());
			out.push_back(more);
		}


		for (int i = 0; i < str_n2; i++) {
			string t1 = n1.substr(str_n2 - i - 1, 1);
			string t2 = n2.substr(str_n2 - i - 1, 1);
			int x1 = atoi(t1.c_str());
			int x2 = stoi(t2.c_str());
			int sum = x1 + x2 + jinwei;

			if (sum > 9) {
				jinwei = 1;
				sum = sum - 10;
				out.push_back(sum);
			}
			else {
				jinwei = 0;
				out.push_back(sum);
			}
		}
	}
	else{
		for (int i = 0; i < str_n2; i++) {
			string t1 = n1.substr(str_n2 - i - 1, 1);
			string t2 = n2.substr(str_n2 - i - 1, 1);
			int x1 = atoi(t1.c_str());
			int x2 = stoi(t2.c_str());
			int sum = x1 + x2 + jinwei;
			if (sum > 9) {
				jinwei = 1;
				sum = sum - 10;
				out.push_back(sum);
			}
			else {
				jinwei = 0;
				out.push_back(sum);
			}
		}
	}
	cout << zhengshu_int_n1 + zhengshu_int_n2 << ".";
	for (int i = out.size(); i > 0; i--) {
		cout << out[i - 1] ;
	}

	return 0;
}
