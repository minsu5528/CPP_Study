int Simple(int a = 10) {
	return a + 1;
}

int Simple(void) {
	return 10;
}

->  함수 오버로딩은 되어 컴파일은 가능하지만 
	인자를 전달하지 않고 함수를 호출하는 경우 두 함수 모두 호출조건을 만족하므로 컴파일 에러가 발생한다. 