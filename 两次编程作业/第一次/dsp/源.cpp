#include <iostream>
#include <vector>
#include <string>
using namespace std;

class seq {
public:
	vector<double> a;
	int begin;
	int end;


	seq() {
		this->begin = -2;
		this->end = 2;
		for (int i = 1; i <=5; i++) {
			a.push_back(i);
		}
	}
	seq(int b, int e, vector<double> temp) {
		begin = b;
		end = e;
		a = temp;
	}
	void init();
	void display();
	int getNum(int index);
	void changeNum(int index,double afterNum);
	seq supplement(int flag, int num);
	seq move(int flag, int num);
	seq reverse();
	seq wider(int num);
	seq shorter(int num);
	double accumulate();
	seq difference(int num);
	vector<double> difference0(vector<double> temp);

	//加法
	void operator+(seq & b) {
		//补零
		if (this->begin < b.begin) {
			b = b.supplement(1, b.begin - this->begin);
		}
		else {
			supplement(1, this->begin - b.begin);
		}
		if (this->end < b.end) {
			supplement(0, b.end-this->end);
		}
		else {
			b = b.supplement(0, this->end - b.end);
		}
	/*	cout << "a:";
		this->display();
		cout << "b:";
		b.display();*/
		//处理
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] + b.a[i] << ' ';
		}
		cout << endl;
	}
	/*
	void operator*(seq b) {
		//补零
		if (this->begin < b.begin) {
			b = b.supplement(1, b.begin - this->begin);
		}
		else {
			supplement(1, this->begin - b.begin);
		}
		if (this->end < b.end) {
			supplement(0, b.end - this->end);
		}
		else {
			b = b.supplement(0, this->end - b.end);
		}
		cout << "a:";
		this->display();
		cout << "b:";
		b.display();
		//处理
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] * b.a[i] << ' ';
		}
	}*/
	
	//乘法
	void operator-(seq & b) {
		//补零
		if (this->begin < b.begin) {
			b = b.supplement(1, b.begin - this->begin);
		}
		else {
			supplement(1, this->begin - b.begin);
		}
		if (this->end < b.end) {
			supplement(0, b.end - this->end);
		}
		else {
			b = b.supplement(0, this->end - b.end);
		}
		//处理
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] * b.a[i] << ' ';
		}
		cout << endl;
	}

	//卷积
	seq operator*(seq b) {
		vector<double> result;
		double temp;
		double t2 = 0;
		for (int i = 0; i < this->a.size() + b.a.size() - 1; i++) {
			for (int j = 0; j < this->a.size(); j++) {
				if (((i - j )> (b.a.size()-1)) || (i - j < 0)) {
					temp = 0;
				}
				else temp = b.a[i-j];
				t2=t2+ temp * a[j];
			//	result.push_back(temp * a[j]);
			}
			result.push_back(t2);
			t2 = 0;
		}
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		seq t(0, result.size(), result);
		return t;
	}

	//滑动窗的相似性比对
	void operator&(seq b) {
		seq temp = b.reverse();
		*this* temp;	//将this与反转后的b 两个序列卷积
	}
	//归一化的相似性比对
	void operator^(seq b) {
		/*
		seq temp = *this * b;//分子序列
		double temp1 = 0;
		double temp2 = 0;
		double temp3;	//分母
		for (int i = 0; i < a.size(); i++) {
			temp1 = temp1 + a[i] * a[i];
		}
		for (int i = 0; i < b.a.size(); i++) {
			temp2 = temp2 + b.a[i] * b.a[i];
		}
		temp3 = temp1 * temp2;
		temp3 = sqrt(temp3);

		vector<double> res;
		for (int i = 0; i < temp.a.size(); i++) {
			res.push_back(temp.a[i] / temp3);
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}*/
		double temp1 = 0;
		double temp2 = 0;
		for (int i = 0; i < a.size(); i++) {
			temp1 = temp1 + a[i] * a[i];
		}
		for (int i = 0; i < b.a.size(); i++) {
			temp2 = temp2 + b.a[i] * b.a[i];
		}
		double temp3 = sqrt(temp1);
		vector<double> tempA;
		vector<double> tempB;
		for (int i = 0; i < a.size(); i++) {
			tempA.push_back(a[i] / temp3);
		}
		temp3 = sqrt(temp2);
		for (int i = 0; i < b.a.size(); i++) {
			tempB.push_back(b.a[i] / temp3);
		}
		seq A2(this->begin, this->end, tempA);
		seq B2(b.begin, b.end, tempB);
		cout << "归一化原序列A:" << endl;
		A2.display();
		cout << "归一化原序列B:" << endl;
		B2.display();
		cout << "归一化后结果:";
		A2 & B2;
	}
};
void seq::init() {
	cout << "please input begin:";
	cin >> this->begin;
	cout << "please input end:";
	cin >> this->end;
	cout << "please input content" << endl;
	string temp;
	while (cin >> temp) {
		a.push_back(stoi(temp));
		if (cin.get() == '\n') break;
	}
}
//显示 输出
void seq::display() {
	cout << "begin:" << this->begin << endl;
	cout << "end:" << this->end << endl;
	for (int i=0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
//通过n获取数据
int seq::getNum(int index) {
	return this->a[index - this->begin];
}
//修改序列数据
void seq::changeNum(int index, double afterNum) {
	this->a[index - this->begin] = afterNum;
}
//补零
seq seq::supplement(int flag, int num) {
	//flag==1 左侧补零
	if (flag == 1) {
		for (int i = 0; i < num; i++) {
			this->a.insert(a.begin(), 0);
		}
		this->begin = this->begin - num;
	}
	//flag==0，右侧补零
	else {
		for (int i = 0; i < num; i++) {
			this->a.push_back(0);
		}
		this->end = this->end + num;
	}
	return *this;
}
//序列延迟、提前操作
seq seq::move(int flag, int num) {
	//flag==1，减法，相当于延迟
	if (flag == 1) {
		this->begin -= num;
		this->end -= num;
	}
	//加法，提前
	else {
		this->begin += num;
		this->end += num;
	}
	return *this;
}
//翻转
seq seq::reverse() {
	int len = this->a.size();
	double temp = 0;
	for (int i = 0; i < len / 2; i++) {
		temp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = temp;
	}
	temp = begin;
	begin = end * (-1);
	end = temp * (-1);
	return *this;
}
//拉伸
seq seq::wider(int num) {
	vector<double> temp;
	for (int i = 0; i < (end*num-begin*num+1); i++) {
		if (i % num == 0) 
			temp.push_back(this->a[i / num]);
		else 
			temp.push_back(0);
	}
	seq t(this->begin * num, end * num, temp);
	return t;
}
//压缩
seq seq::shorter(int num) {
	vector<double> temp;
	for (int i = abs(begin)%num; i < (end  - begin  + 1); i=i+num) {
		temp.push_back(a[i]);
	}
	seq t(begin / num, end / num, temp);
	return t;
}
//累加
double seq::accumulate() {
	/*
	vector<int> temp = {};
	temp.push_back(a[0]);
	for (int i = 1; i < a.size(); i++) {
		temp.push_back(temp[i - 1] + a[i]);
	}
	seq temp2(begin, end, temp);
	*/
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum = sum + a.at(i);
	}
	return sum;
}
//差分
seq seq::difference(int num) {
	vector<double> temp=this->a;
	for (int i = 0; i < num; i++) {
		temp = this->difference0(temp);
	}
	seq t(begin, end - num, temp);
	return t;
}
vector<double> seq::difference0(vector<double> temp) {
	vector<double> t2;
	for (int i = 0; i < temp.size()-1; i++) {
		t2.push_back(temp[i + 1] - temp[i]);
	}
	return t2;
}

int main() {          
	cout << "input flag:" << endl;
	int flag;
	/*cin >> flag;*/
	flag = 1;
	if (flag == 0) {
		/*
		vector<double> u = { 3,4,5,5,5 };
		seq A(0, 4, u);
		//vector<int> u2 = { 3,4,1 };
		vector<double> u2 = { 6,8,10,11,10 };
		seq B(0, 4, u2);*/
		vector<double> u = { 3,4,5,5,5 };
		seq A(0, 4, u);
		//vector<int> u2 = { 3,4,1 };
		vector<double> u2 = { 6,8,10,11,10 };
		seq B(0,4, u2);
		cout << "原序列A:" << endl;
		A.display();
		cout << "原序列B:" << endl;
		B.display();
		//cout << "加法结果:";
		//A + B;

	/*	cout << endl;
		cout << "乘法结果:"; 
		A - B;
		cout << endl;
		cout << "卷积结果:";
		A * B;*/
		//cout << "相似性结果:";
	//	A & B;
		
		A ^ B;
	}
	else if (flag == 1) {
		vector<double> u = { 5,9,4,1,6 };
		seq A(0, 4, u);
		vector<double> u2 = { 1,2,3 };
		seq B(0,2, u2);
		int in1, in2;
		/*
		cout << "请选择将要进行的操作：" << endl;
		cout << "1.加法	2:乘法	3.相关性计算	" << endl;
		int op;
		cin >> op;
			
		switch (op)
		{
		case 1:
			cout << "初始化加法结果：";
			A + B;
			cout << endl;
			break;
		case 2:
			cout << "初始化卷积结果：";
			A* B;
			cout << endl;
			break;
		default:
			break;
		}

		*/
		cout << "初始化序列：" << endl;
		A.display();
		/*A.display();
		B.display();*/
		seq temp;
		while (1) {
			cin >> in1;
			//cin >> in2;
			A.a.push_back(in1);
			A.end += 1;
		//	B.a.push_back(in2);
			temp = A.difference(2);
			cout << "n重差分结果：";
			temp.display();	
		}
	}
	else {
		cout << "输入不合法" << endl;
		return -1;
	}
	return 0;
}