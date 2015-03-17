#include <iostream> 
using namespace std; 

//使用 new 和 delete 動態配置一個變數

void dynamic_var() {
	//使用 new 動態配置一個變數
	int *ptr = new int(100); 
	
	cout << "空間位置:" << ptr << endl; 
	cout << "空間儲存值：" << *ptr << endl; 
	
	*ptr = 200; 
	
	cout << "空間位置:" << ptr << endl;
	cout << "空間儲存值：" << *ptr << endl;

	//使用 delete 釋放記憶體
	delete ptr; 
}

//使用 new 和 delete 動態配置一維陣列

void dynamic_array() {
	int size = 0; 

	cout << "請輸入陣列長度："; 
	cin >> size; 
	int *arr = new int[size]; 

	cout << "指定元素值：" << endl; 
	for(int i = 0; i < size; i++) { 
		cout << "arr[" << i << "] = "; 
		cin >> *(arr+i); 
	} 

	cout << "顯示元素值：" << endl; 
	for(int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = " << *(arr+i) << endl; 
	} 

	delete [] arr; 
}

int main(){
	cout << "使用 new 和 delete 動態配置一個變數：\n";
	dynamic_var();
	cout << "使用 new 和 delete 動態配置一維陣列：\n";
	dynamic_array();
	return 0;
}

	//使用 new 運算子動態配置的空間，在整個程式結束前並不會自動歸還給記憶體
	//您必須使用 delet e將這個空間還給記憶體，如上面的程式在結束前所作的動作
	//在這個程式中，雖然顯示完畢後程式也就結束，但這邊還是示範 delete 的用法，而這也是個好習慣，
	//日後您的程式在持續執行過程中若大量使用new而 沒有適當的使用delete的話，由於空間一直沒有歸還，最後將導致整個記憶體空間用盡。 
