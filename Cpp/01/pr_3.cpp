#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

struct citizen
{
	string name;
	int age;
};

ostream &operator<<(ostream &os,const citizen &c)
{
	return (os<<"["<<c.name<<", "<<c.age<<"]");
}

int main()
{
	forward_list<citizen> citizens=
	{
		{"Kim",22},{"Lee",25},{"Park",18},{"Jin",16}	
	};
	
	auto citizens_copy=citizens; // 깊은 복사
	
	cout<<"전체 시민들 : ";
	for(const auto &c:citizens)
		cout<<c<<" ";
	cout<<endl;
	
	citizens.remove_if( // remove_if 함수는 true를 반환하는 모든 원소를 리스트에서 삭제함
	[](const citizen &c) // 람다함수
	{
		return (c.age<19);
	}
	);
	
	cout<<"투표권이 있는 시민들 : ";
	for(const auto &c:citizens)
		cout<<c<<" ";
	cout<<endl;
	
	citizens_copy.remove_if(
	[](const citizen &c)
	{
		return (c.age!=18);
	}
	);
	
	cout<<"내년에 투표권이 생기는 시민들 : ";
	for(const auto &c:citizens_copy)
		cout<<c<<" ";
	cout<<endl;
	
	return 0;
}
