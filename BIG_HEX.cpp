#include<iostream>
using namespace std;
class Big_Hex{
private:
	char* hex;
	int length;

   public:
	Big_Hex(){
		hex = nullptr;
	    length = 0;
	}
	Big_Hex(const char* _hex) {
		int len = strlen(_hex);
		hex = new char[len + 1];
		for (int i = 0; i < len; i++) {
			hex[i] = _hex[i];
		}
		hex[len] = '\0';
		length = len;

	}
	Big_Hex(const Big_Hex& obj) {
		int count = obj.length;
		this->hex = new char[count + 1];
		int i = 0;
		for (; i < count; i++) {
			this->hex[i] = obj.hex[i];
		}
		this->hex[count] = '\0';
		length = count;
	}
	void removeZeros() {
		bool stop = false;
		for (int i = 0; i < this->length && stop == false; i++) {
			if (this->hex[i] != 0) {
				stop = true;
			}
			else if(this->hex[i] == 0) {
				this->hex[i] = this->hex[i + 1];
				this->length--;
			}
			
		}

	}
	Big_Hex& operator=(const Big_Hex& obj) {
		
		this->hex = new char[obj.length + 1];
		for (int i = 0; i <obj.length; i++) {
			this->hex[i] = obj.hex[i];
		}
		this->hex[obj.length] = '\0';
		this->length = obj.length;
		return *this;

	}
	Big_Hex& operator=(const char* _hex) {
		int count = strlen(_hex);
		
		this->hex = new char[count+1];
		for (int i = 0; i < count; i++) {
			this->hex[i] = _hex[i];
		}
		this->hex[count] = '\0';
		this->length = count;
		return *this;

	}
	Big_Hex  operator++(int) {   //i++

		Big_Hex big1("1");
		Big_Hex big2("1");
		big2 = *this;
		*this = *this + big1;


		return big2;
	}
	 
	Big_Hex operator++() {  //++i
		Big_Hex big1("1");
		*this = *this + big1;
		return *this;


	}
	Big_Hex operator--(int) {
		Big_Hex big1("1");
		Big_Hex big2("*this");
		*this = *this - big1;
		return big2;
	}
	Big_Hex operator--() {
		Big_Hex big1("1");
		*this = *this - big1;
		return *this;


	}
	Big_Hex& operator+= (const Big_Hex&obj) {
		*this = *this + obj;
		return *this;

	}
	char& operator[](int i) {
		if (i >= this->length) {
			cout << "Array index out of bound\n";
		}
		else
			return this->hex[i];

	}
	char* operator()(int f, int l) {
		char* temp = new char[(l - f)+2];
		if (l > this->length) {
			temp = nullptr;
		}
		int k = 0;
		for (int i = f; i <= l;k++, i++) {
			temp[k] = this->hex[i];
		}
		temp[k]= '\0';
		return temp;

	}
	friend bool operator< (const Big_Hex&, const Big_Hex&);
	friend bool operator==(const Big_Hex&, const Big_Hex&);
	friend Big_Hex operator+ (const Big_Hex&, const Big_Hex&);
	friend ostream& operator <<(ostream&, const Big_Hex&);
	friend Big_Hex operator* (const Big_Hex&, const Big_Hex&);
	friend Big_Hex operator- (const Big_Hex&, const Big_Hex&);
	friend Big_Hex operator/ (const Big_Hex&, const Big_Hex&);
	friend bool operator<=(const Big_Hex&, const Big_Hex&);
	friend istream& operator>>(istream&, Big_Hex&);
	friend ostream& operator <<(ostream& cout, const Big_Hex& obj);
	friend Big_Hex operator% (const Big_Hex&, const Big_Hex&);

	~Big_Hex() {
		delete hex;

	}


};
int* hextoint(const char* hex) {
	int* i = new int[strlen(hex) + 1];
	for (int j = 0; j < strlen(hex); j++) {
		if (hex[j] >= '0' && hex[j] <= '9') {
			if (hex[j] == '0') i[j] = 0;
			else if (hex[j] == '1')i[j] = 1;
			else if (hex[j] == '2')i[j] = 2;
			else if (hex[j] == '3')i[j] = 3;
			else if (hex[j] == '4')i[j] = 4;
			else if (hex[j] == '5')i[j] = 5;
			else if (hex[j] == '6')i[j] = 6;
			else if (hex[j] == '7')i[j] = 7;
			else if (hex[j] == '8')i[j] = 8;
			else if (hex[j] == '9')i[j] = 9;

		}
		if (hex[j] >= 'a' && hex[j] <= 'f') {
			i[j] = hex[j] - 32;
			if (i[j] == 65)i[j] = 10;
			if (i[j] == 66)i[j] = 11;
			if (i[j] == 67)i[j] = 12;
			if (i[j] == 68)i[j] = 13;
			if (i[j] == 69)i[j] = 14;
			if (i[j] == 70)i[j] = 15;

		}
		if (hex[j] >= 'A' && hex[j] <= 'F') {
			if (hex[j] == 'A')i[j] = 10;
			if (hex[j] == 'B')i[j] = 11;
			if (hex[j] == 'C')i[j] = 12;
			if (hex[j] == 'D')i[j] = 13;
			if (hex[j] == 'E')i[j] = 14;
			if (hex[j] == 'F')i[j] = 15;
		}
	}

	return i;

}
char* inttohex(int i[], int size) {
	char* h = new char[size + 1];
	for (int k = size - 1, l = 0; k >= 0; k--, l++) {

		if (i[k] == 0)h[l] = '0';
		else if (i[k] == 1)h[l] = '1';
		else if (i[k] == 2)h[l] = '2';
		else if (i[k] == 3)h[l] = '3';
		else if (i[k] == 4)h[l] = '4';
		else if (i[k] == 5)h[l] = '5';
		else if (i[k] == 6)h[l] = '6';
		else if (i[k] == 7)h[l] = '7';
		else if (i[k] == 8)h[l] = '8';
		else if (i[k] == 9)h[l] = '9';
		else if (i[k] == 10)h[l] = 'A';
		else if (i[k] == 11)h[l] = 'B';
		else if (i[k] == 12)h[l] = 'C';
		else if (i[k] == 13)h[l] = 'D';
		else if (i[k] == 14)h[l] = 'E';
		else if (i[k] == 15)h[l] = 'F';
	}
	h[size] = '\0';
	return h;

}
bool operator< (const Big_Hex& hex1, const Big_Hex& hex2) {
	for (int i = 0; i < hex1.length; i++) {
		if (hex1.hex[i] >= 'a' && hex1.hex[i] <= 'z') {
			hex1.hex[i] = hex1.hex[i] - 32;

		}
	}
	for (int i = 0; i < hex2.length; i++) {
		if (hex2.hex[i] >= 'a' && hex2.hex[i] <= 'z') {
			hex2.hex[i] = hex2.hex[i] - 32;
		}
	}
	bool same = true;
	if (hex1.length > hex2.length) {
		return false;
	}
	else if (hex2.length > hex1.length) {
		return true;
	}
	else if (hex1.length == hex2.length) {

		for (int i = 0; i < hex1.length && same == true; i++) {
			if (hex1.hex[i] == hex2.hex[i]) {
				same = true;

			}
			else if (hex1.hex[i] > hex2.hex[i]) {
				return false;
			}
			else if (hex1.hex[i] < hex2.hex[i]) {
				return true;
			}
		}
	}
	if (same == true) {
		return false;
	}
}
bool operator==(const Big_Hex&hex1, const Big_Hex&hex2) {
	if (hex1.length != hex2.length) {
		return false;
	}
	if (hex1.hex == nullptr || hex2.hex == nullptr) {
		return false;
	}
	else {
		bool match = true;
		for (int i = 0; i < hex1.length && match == true; i++) {
			if (hex1.hex[i] == hex2.hex[i]) {
				match = true;
			}
			else if ((hex1.hex[i] - 32) == hex2.hex[i]) {
				match = true;
			}
			else if (hex1.hex[i] == (hex2.hex[i] - 32)) {
				match = true;
			}
			else match = false;
		}
		return match;
	}

 }
bool operator<=(const Big_Hex& hex1, const Big_Hex& hex2) {
	if (hex1 == hex2 || hex1 < hex2) {
		return true;
	}
	else
		return false;
 }
Big_Hex operator+ (const Big_Hex& hex1, const Big_Hex& hex2) {
	int n1 = hex1.length - 1, n2 = hex2.length - 1;
	int* a, * b;
	if (n1 > n2) {
		a = hextoint(hex2.hex);
		b = hextoint(hex1.hex);

	}
	else
	{
		a = hextoint(hex1.hex);
		b = hextoint(hex2.hex);
		n1 = hex2.length - 1;
		n2 = hex1.length - 1;
	}
	int* ans = new int[100];
	for (int i = 0; i < 100; i++) {
		ans[i] = 0;
	}
	int i = 0, sum = 0, carry = 0;
	for (; n2 >= 0; n1--, n2--, i++) {
		sum = carry + a[n2] + b[n1];
		if (sum > 15) {
			ans[i] = sum % 16;
			carry = sum / 16;
		}
		else {
			ans[i] = sum;
			carry = 0;
		}
		sum = 0;
	}
	//appending remaining digits
	for (; n1 >= 0; n1--, i++) {
		sum = carry + b[n1];
		if (sum > 15) {
			ans[i] = sum % 16;
			carry = sum / 16;
		}
		else {
			ans[i] = sum;
			carry = 0;
		}
		sum = 0;
	}
	Big_Hex temp;
	temp.hex = inttohex(ans, i);
	temp.length = i;
	delete[] a;
	delete[] b;
	delete[]ans;
	return temp;
	
}
Big_Hex operator* (const Big_Hex&hex1, const Big_Hex&hex2) {
	int n1 = hex1.length - 1, n2 = hex2.length - 1;
	int* a, * b;
	int* ans = new int[100];
	for (int i = 0; i < 100; i++) {
		ans[i] = 0;
	}
	if (n1 > n2) {
		a = hextoint(hex2.hex);
		b = hextoint(hex1.hex);

	}
	else{
		a = hextoint(hex1.hex);
		b = hextoint(hex2.hex);
		n1 = hex2.length - 1;
		n2 = hex1.length - 1;
	}
	int i = 0,j=0,k=0, carry = 0, mul = 0, index = 0,size=0;
	if (n1 == 0 && b[0] == 0) {
		size = 1;
	}
	else if (n2 == 0 && a[0] == 0) {
		size = 1;
	}
	else {
		for (; n1 >= 0; n1--, i++) {
			for (j = i, k = n2; k >= 0; k--, j++) {
				mul = ((b[n1] * a[k]) + carry) + ans[j];
				if (mul > 15) {
					ans[j] = mul % 16;
					carry = mul / 16;
				}
				else {
					ans[j] = mul;
					carry = 0;
				}

			}
			ans[j] = carry;
			carry = 0;
			size = j+1 ;
		}
	}
	for (; ans[size-1] == 0;) { //removing extra zeros
		size--;
	}
	
	Big_Hex temp;
	temp.hex = inttohex(ans, size);
	temp.length = size;
	delete[] a;
	delete[] b;
	delete[]ans;

	return temp;
	
}
Big_Hex operator- (const Big_Hex&hex1, const Big_Hex&hex2){
	int n1 = 0 ,n2 = 0;
	int* a, * b;
	bool stop = false;

		a = hextoint(hex2.hex);
		b = hextoint(hex1.hex);
		n1 = hex1.length - 1;
		n2 = hex2.length - 1;
	
	int* ans = new int[100];
	for (int i = 0; i < 100; i++) {
		ans[i] = 0;
	}
	int i = 0, carry = 0,sub=0,index=0;
	for (; n2 >=0; n1--, n2--, i++) {
		if (b[n1] > a[n2]) {
			sub = (b[n1] + carry) - a[n2];
		}
		else {
			index = n1 - 1;
			while (!stop){
				if (b[index] != 0) {
					stop = true;
				}
				else
				index--;
			}
			b[index]=b[index] - 1;
			index++;
			while (b[index ] != b[n1]) {
				b[index] = (b[index] + 16) - 1;
				index++;
			}
			sub = ((b[n1] + 16) + carry) -a[n2];

		}
		if (sub > 15) {
			ans[i] = sub % 16;
			carry = sub / 16;
		}
		else {
			ans[i] = sub;
			carry = 0;

		}
		sub = 0;
	}
	for (; n1 >= 0; n1--, i++) {
		sub = carry + b[n1];
		if (sub> 15) {
			ans[i] = sub % 16;
			carry = sub / 16;
		}
		else {
			ans[i] = sub;
			carry = 0;
		}
		sub = 0;
	}
	bool zero=true;
	for (int k = i;zero==true ; k--) {      //removing leading zeros
		if (ans[k] != 0) {
			zero = false;
		}
		else i--;
		
	}
	Big_Hex temp;
	temp.hex = inttohex(ans, i+1);
	temp.length = i+1;
	delete[] a;
	delete[] b;
	delete[]ans;
	return temp;
	

}
Big_Hex operator/ (const Big_Hex& hex1, const Big_Hex& hex2) {
	int n1 = 0, n2 = 0;
	
	int* q = new int[100];
	
	n1 = hex1.length - 1;
	n2 = hex2.length - 1;
	Big_Hex temp;
	int i = 0,size=n1;
	int* ans=new int[100];
	
	for (int i = 0; i < 100; i++) {
		ans[i] = '0';
	}
	if (hex1 == hex2) {
		ans[i] = 1;
		i++;
		temp.hex = inttohex(ans, i);
		temp.length = i;
		return temp;

	}
	else {
		bool stop = false, end = false, addzero = false;
		Big_Hex temp, remainder;
		int tempsize = n2;
		char* t = new char[tempsize + 1];
		size = size - tempsize;
		for (int j = 0; j < tempsize + 1; j++) {
			t[j] = hex1.hex[j];
		}
		
		for (int j = 0; j < 100; j++) {
			q[j] = 0;
		}
		temp.hex = t;
		temp.length = tempsize + 1;
		
		Big_Hex temp2 = hex2;
		for (; end == false;) {          //loop starts here
			stop = false;
			int zerocount = 0;

			while (temp < hex2 && size!=0) {
				tempsize++;
				size--;

				char* newchar = new char[temp.length + 2];
				int k = 0;
				for (; k < temp.length; k++) {
					newchar[k] = temp.hex[k];
				}
				for (int l = tempsize; k < (temp.length + 1); k++) {
					newchar[k] = hex1.hex[l];
				}
				temp = newchar;
				delete[] newchar;
				temp.length = k;
				if (addzero == true && zerocount > 0) {

					ans[i++] = 0;
				}
				zerocount++;
				temp.removeZeros();
				
			}
			Big_Hex mul("2");
			if (temp == temp2) {
				mul--;
			}
			

			else if (size == 0) {
				if (temp < hex2) {
					mul = "0";
				}
				else {
					for (; stop == false; ) {
						temp2 = hex2 * mul;
						if (temp2 < temp) {
							mul++;
							if (temp2 == temp) {
								stop = true;
							}
						}
						else
							stop = true;
					}
				}
				mul--;
			}
			else {
				for (; stop == false; ) {
					temp2 = hex2 * mul;
					if (temp2 < temp) {
						mul++;
						if (temp2 == temp) {
							stop = true;
						}
					}
					else
						stop = true;
				}
				mul--;
			}
			
				temp = temp - (hex2 * mul);
			
				ans = hextoint(mul.hex);
				int sizeans = mul.length;
				for (int g = 0; g < sizeans; g++, i++) {
					q[i] = ans[g];
				}
				if (size == 0) {
					end = true;
				}

				addzero = true;
			
		}
		delete[] t;

	}
	
	Big_Hex temp3;
	temp3.hex = inttohex(q, i);
	temp3.length = i;
	Big_Hex qoutient;
	qoutient.length = i ;
	qoutient.hex = new char[i+1];
	for (int q = 0, s = temp3.length-1; s >= 0; s--, q++) {
		qoutient.hex[q] = temp3.hex[s];
	}
	qoutient.hex[qoutient.length] = '\0';
	delete[] q;
	delete[] ans;
	return qoutient;
}
Big_Hex operator% (const Big_Hex& hex1, const Big_Hex& hex2) {
	Big_Hex mod;
	Big_Hex qou = hex1 / hex2;
	mod = hex1 - (hex2 * qou);
	return mod;
}

istream& operator>>(istream&in, Big_Hex&obj) {
	char temp[1000];
	cin.getline(temp, 1000);
	obj.length = strlen(temp);
	obj.hex = new char[obj.length + 1];
	for (int i = 0; i < obj.length; i++) {
		obj.hex[i] = temp[i];
	}
	obj.hex[obj.length] = '\0';
	return  cin;
	
}
ostream& operator <<(ostream& out , const Big_Hex&obj) {
	out << obj.hex;
	return out;
}
int main() {
	
	Big_Hex hex1("abcd1234");							//hex1 = abcd1234
	Big_Hex hex2("909e81f2002");						//hex2 = 909E81F2002
	Big_Hex hex3 = hex2+hex1;
	Big_Hex hex4 = hex2 / hex1;
	cout << hex2 << "+" << hex1 << "=" << hex3 << endl;
	cout << hex2 << "/" << hex1 << ":" << hex4 << "\n\n\n";
	
	cout << "Enter A Hex Number: ";
	Big_Hex temp;
	cin >> temp;

	hex3 = temp + hex1 - (hex3 % hex4) * (hex2 / hex4);

	cout << hex3 << endl;

	cout << temp;

	hex3 += temp++;		
	hex4 = --hex1;
	cout << endl;

	if (hex2 < hex1&& !(temp == hex4)) {				
		cout << "Expression is Valid" << endl;
	}
	else
	{												
		cout << "Expression NOT Valid" << endl;
	}
	char charAt3 = hex3[3];
	char* charfrom3till7 = hex3(3, 7);
	cout << charAt3 << endl;
	if (charfrom3till7 != nullptr) {
		cout << charfrom3till7 << endl;
		delete[] charfrom3till7;
	}
	
}






