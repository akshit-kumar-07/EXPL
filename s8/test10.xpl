decl
	int n, a[5], fun1(int n);
enddecl
int main(){
	decl
		int  temp1, temp2;
	enddecl
	begin
		fun1(4) = 6;
		fun1 = 10;
		fun1() = 12;
		
		
		return 0;
	end
}

