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

	//�ӷ�
	void operator+(seq & b) {
		//����
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
		//����
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] + b.a[i] << ' ';
		}
		cout << endl;
	}
	/*
	void operator*(seq b) {
		//����
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
		//����
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] * b.a[i] << ' ';
		}
	}*/
	
	//�˷�
	void operator-(seq & b) {
		//����
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
		//����
		cout << "result:";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] * b.a[i] << ' ';
		}
		cout << endl;
	}

	//���
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

	//�������������Աȶ�
	void operator&(seq b) {
		seq temp = b.reverse();
		*this* temp;	//��this�뷴ת���b �������о��
	}
	//��һ���������Աȶ�
	void operator^(seq b) {
		/*
		seq temp = *this * b;//��������
		double temp1 = 0;
		double temp2 = 0;
		double temp3;	//��ĸ
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
		cout << "��һ��ԭ����A:" << endl;
		A2.display();
		cout << "��һ��ԭ����B:" << endl;
		B2.display();
		cout << "��һ������:";
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
//��ʾ ���
void seq::display() {
	cout << "begin:" << this->begin << endl;
	cout << "end:" << this->end << endl;
	for (int i=0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
//ͨ��n��ȡ����
int seq::getNum(int index) {
	return this->a[index - this->begin];
}
//�޸���������
void seq::changeNum(int index, double afterNum) {
	this->a[index - this->begin] = afterNum;
}
//����
seq seq::supplement(int flag, int num) {
	//flag==1 ��ಹ��
	if (flag == 1) {
		for (int i = 0; i < num; i++) {
			this->a.insert(a.begin(), 0);
		}
		this->begin = this->begin - num;
	}
	//flag==0���Ҳಹ��
	else {
		for (int i = 0; i < num; i++) {
			this->a.push_back(0);
		}
		this->end = this->end + num;
	}
	return *this;
}
//�����ӳ١���ǰ����
seq seq::move(int flag, int num) {
	//flag==1���������൱���ӳ�
	if (flag == 1) {
		this->begin -= num;
		this->end -= num;
	}
	//�ӷ�����ǰ
	else {
		this->begin += num;
		this->end += num;
	}
	return *this;
}
//��ת
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
//����
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
//ѹ��
seq seq::shorter(int num) {
	vector<double> temp;
	for (int i = abs(begin)%num; i < (end  - begin  + 1); i=i+num) {
		temp.push_back(a[i]);
	}
	seq t(begin / num, end / num, temp);
	return t;
}
//�ۼ�
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
//���
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
		cout << "ԭ����A:" << endl;
		A.display();
		cout << "ԭ����B:" << endl;
		B.display();
		//cout << "�ӷ����:";
		//A + B;

	/*	cout << endl;
		cout << "�˷����:"; 
		A - B;
		cout << endl;
		cout << "������:";
		A * B;*/
		//cout << "�����Խ��:";
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
		cout << "��ѡ��Ҫ���еĲ�����" << endl;
		cout << "1.�ӷ�	2:�˷�	3.����Լ���	" << endl;
		int op;
		cin >> op;
			
		switch (op)
		{
		case 1:
			cout << "��ʼ���ӷ������";
			A + B;
			cout << endl;
			break;
		case 2:
			cout << "��ʼ����������";
			A* B;
			cout << endl;
			break;
		default:
			break;
		}

		*/
		cout << "��ʼ�����У�" << endl;
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
			cout << "n�ز�ֽ����";
			temp.display();	
		}
	}
	else {
		cout << "���벻�Ϸ�" << endl;
		return -1;
	}
	return 0;
}