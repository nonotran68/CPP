## **Bài 2.5: <u> Giới thiệu về phạm vi cục bộ</u>**

### **Biến cục bộ**

Biến được khai báo bên trong thân hàm được gọi là **biến cục bộ** (trái ngược với **biến toàn cục**, chúng ta sẽ thảo luận trong chương sau):
>```
>int add(int x, int y) {
>  int z{ x + y }; // z là biến cục bộ
>  return z;
>}
>```

Tham số hàm cũng thường được coi là biến cục bộ và chúng ta sẽ xếp chúng vào loại đó:
>```
>int add(int x, int y) // tham số hàm x và y là biến cục bộ
>{
>  int z{ x + y };
>  return z;
>}
>```

Trong bài học này, chúng ta sẽ xem xét chi tiết một số thuộc tính của biến cục bộ.



### **Vòng đời của biến cục bộ**

Trong **[bài học 1.3 - Đối tượng và biến trong C++](../lesson1/lesson1_3.ipynb)**, chúng ta đã thảo luận về cách khai báo biến như `int x;` sẽ khiến biến được khởi tạo khi câu lệnh này được thực thi. Tham số hàm được tạo và khởi tạo khi hàm được nhập, và các biến trong thân hàm được tạo và khởi tạo tại điểm khai báo.

**Ví dụ:**

>```
>int add(int x, int y) // x và y được tạo và khởi tạo tại đây
>{
>  int z{ x + y };   // z được tạo và khởi tạo tại đây
>  return z;
>}
>```

Câu hỏi tiếp theo được đặt ra là, "Vậy một biến được khởi tạo thì bị hủy khi nào?". Biến cục bộ bị hủy theo thứ tự ngược lại với thứ tự tạo ở cuối cặp ngoặc nhọn nơi nó được khai báo (hoặc đối với tham số hàm, ở cuối hàm).

**Dễ hiểu hơn**
- **Tạo:**
  - Biến cục bộ được tạo khi chúng được khai báo trong thân hàm hoặc khối mã khác.
  - Tham số hàm cũng được coi là biến cục bộ và được tạo khi hàm được gọi.
  - Biến cục bộ được khởi tạo với giá trị mặc định của kiểu dữ liệu của chúng khi được tạo.
- **Hủy:**
  - Biến cục bộ bị hủy khi khối mã nơi chúng được khai báo kết thúc.
  - Biến cục bộ không thể được truy cập sau khi chúng bị hủy.

>```
>int add(int x, int y)
>{
>    int z{ x + y };
>
>    return z; //this is the end of function, any lines after this return doesn't count
>} // z, y, and x destroyed here if there is no return value
>```

Giống như tuổi thọ của một người được xác định là khoảng thời gian giữa khi sinh và khi chết, vòng đời của một đối tượng được xác định là khoảng thời gian giữa khi nó được tạo và bị hủy. Lưu ý rằng việc tạo và hủy biến xảy ra khi **chương trình đang chạy** (gọi là **thời gian chạy**), không phải tại **thời gian biên dịch**. Do đó, vòng đời là một thuộc tính của **thời gian chạy** (runtime).



>**Đối với người đọc nâng cao**<br>
>Các quy tắc về tạo, khởi tạo và hủy ở trên là những đảm bảo. Nghĩa là, các đối tượng phải được tạo và khởi tạo muộn nhất là tại điểm khai báo và bị hủy không sớm hơn cuối cặp ngoặc nhọn nơi chúng được khai báo (hoặc đối với tham số hàm, ở cuối hàm).
>
>Trên thực tế, đặc tả C++ cung cấp cho trình biên dịch rất nhiều linh hoạt để xác định thời điểm tạo và hủy biến cục bộ. Đối tượng có thể được tạo sớm hơn hoặc hủy muộn hơn vì mục đích tối ưu hóa. Thông thường, biến cục bộ được tạo khi hàm được nhập và hủy theo thứ tự ngược lại với thứ tự tạo khi hàm thoát. Chúng ta sẽ thảo luận chi tiết hơn về điều này trong bài học sau, khi chúng ta nói về ngăn xếp cuộc gọi (**call stack**).

Đây là một chương trình C++ phức tạp hơn một chút để minh họa vòng đời của biến có tên x:

>```
>#include <iostream>
>
>void doSomething()
>{
>    std::cout << "Hello!\n";
>}
>
>int main()
>{
>    int x{ 0 };    // Vòng đời của x bắt đầu tại đây
>
>    doSomething(); // x vẫn tồn tại trong suốt lời gọi hàm này
>
>    return 0;
>} // Vòng đời của x kết thúc tại đây

Trong chương trình trên, vòng đời của `x` bắt đầu từ điểm khai báo đến cuối hàm `main`. Điều này bao gồm thời gian thực thi hàm `doSomething`.

**Phân tích chi tiết:**

- Dòng `int x {0};`: Biến `x` được khai báo kiểu `int` và khởi tạo với giá trị `0`. Lúc này, biến `x` được tạo (khởi tạo vùng nhớ) và tuổi thọ của nó bắt đầu.
- Dòng `doSomething();`: Hàm `doSomething` được gọi. Tuy nhiên, `x` là biến cục bộ của hàm `main` nên nó không bị hủy trong quá trình thực thi `doSomething`. Biến `x` vẫn tồn tại và có thể truy cập được trong suốt lời gọi hàm này.
- Dòng `return 0;`: Hàm `main` kết thúc. Lúc này, biến `x` được đánh dấu để hủy vì nó là biến cục bộ của `main`. Biến `x` không còn khả dụng sau dòng này.


### **Khi một đối tượng bị hủy, điều gì xảy ra?**

Trong hầu hết các trường hợp, không có gì xảy ra. Đối tượng bị hủy trở nên không hợp lệ và bất kỳ việc sử dụng thêm đối tượng đó sẽ dẫn đến **hành vi bất định (undefined behavior)**. Vào một thời điểm nào đó sau khi hủy, bộ nhớ được sử dụng bởi đối tượng sẽ được giải phóng để sử dụng lại.

>**Đối với người đọc nâng cao:**<br>
Nếu đối tượng là một đối tượng kiểu lớp (`class type object`), trước khi hủy, một hàm đặc biệt gọi là hàm hủy (`destructor`) sẽ được kích hoạt. Trong nhiều trường hợp, hàm hủy không làm gì, do đó không phát sinh thêm chi phí nào.

### **Phạm vi cục bộ**

**Phạm vi (scope)** của một định danh xác định vị trí định danh đó có thể được nhìn thấy và sử dụng trong mã nguồn. Khi một định danh có thể được nhìn thấy và sử dụng, chúng ta nói nó **nằm trong phạm vi (in scope)**. Khi một định danh không thể nhìn thấy, chúng ta không thể sử dụng nó và chúng ta nói nó **nằm ngoài phạm vi (out of scope)**. **Phạm vi** là một **thuộc tính** của **thời gian biên dịch (compile-time property)**, và việc cố gắng sử dụng một định danh khi nó không nằm trong phạm vi sẽ dẫn đến **lỗi biên dịch (compile error).**

**Phạm vi của một biến cục bộ** bắt đầu tại điểm khai báo biến và kết thúc ở cuối cặp ngoặc nhọn nơi nó được khai báo (hoặc đối với tham số hàm, ở cuối hàm). Điều này đảm bảo biến không thể được sử dụng trước điểm khai báo (ngay cả khi trình biên dịch chọn tạo chúng trước đó). Biến cục bộ được khai báo trong một hàm cũng không nằm trong phạm vi của các hàm khác được gọi lên sau đó.

>```
>#include <iostream>
>
>// x không nằm trong phạm vi bất cứ nơi nào trong hàm này
>void doSomething()
>{
>    std::cout << "Hello!\n";
>}
>
>int main()
>{
>    // x không thể được sử dụng ở đây vì nó chưa nằm trong phạm vi
>
>    int x{ 0 }; // x bắt đầu nằm trong phạm vi ở đây và bây giờ có thể được sử dụng trong hàm này
>
>    doSomething();
>
>    return 0;
>} // x ra khỏi phạm vi ở đây và không còn được sử dụng nữa
>```

Trong chương trình trên, biến `x` bắt đầu nằm trong phạm vi tại điểm khai báo và ra khỏi phạm vi ở cuối hàm `main`. Lưu ý rằng biến `x` không nằm trong phạm vi bất kỳ nơi nào bên trong hàm `doSomething`. Việc hàm `main` gọi hàm `doSomething` không liên quan trong ngữ cảnh này.

### **"Out of Scope" và "Going Out of Scope"**

Các thuật ngữ "out of scope" (ngoài phạm vi) và "going out of scope" (ra khỏi phạm vi) có thể gây nhầm lẫn cho lập trình viên mới.

#### *<u>Out of Scope (Ngoài phạm vi)</u>*

Một định danh được coi là **"out of scope"** bất cứ nơi nào nó không thể được truy cập trong code. Trong ví dụ trên, định danh `x` nằm trong phạm vi từ điểm khai báo của nó đến cuối hàm `main`. Định danh `x` nằm ngoài phạm vi bên ngoài vùng code đó.

#### *<u>Going Out of Scope (Ra khỏi phạm vi)</u>*

Thuật ngữ **"going out of scope"** thường được áp dụng cho các đối tượng (object) chứ không phải định danh. Chúng ta nói một đối tượng **"goes out of scope" (ra khỏi phạm vi)** ở cuối phạm vi (ngoặc nhọn đóng) nơi đối tượng được khởi tạo. Trong ví dụ trên, đối tượng có tên `x` ra khỏi phạm vi ở cuối hàm `main`.

Vòng đời của một biến cục bộ kết thúc tại thời điểm biến đó ra khỏi phạm vi, vì vậy các biến cục bộ bị hủy tại thời điểm này.

Lưu ý rằng không phải tất cả các kiểu biến đều bị hủy khi chúng ra khỏi phạm vi. Chúng ta sẽ thấy các ví dụ về điều này trong các bài học tương lai.

### **Ví dụ khác** 

Đây là một ví dụ phức tạp hơn một chút. Hãy nhớ rằng, **vòng đời** là thuộc tính của **thời gian chạy (runtime)**, còn **phạm vi** là thuộc tính của **thời gian biên dịch (compile-time)**, vì vậy mặc dù chúng ta đang nói về cả hai trong cùng một chương trình, chúng được áp dụng tại các thời điểm khác nhau.

>```
>#include <iostream>
>
>int add(int x, int y) // x và y được tạo và bắt đầu nằm trong phạm vi ở đây
>{
>    // x và y chỉ nhìn thấy/sử dụng được trong hàm này
>    return x + y;
>} // y và x ra khỏi phạm vi và bị hủy ở đây
>
>int main()
>{
>    int a{ 5 }; // a được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
>    int b{ 6 }; // b được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
>
>    // a và b chỉ sử dụng được trong hàm này
>    std::cout << add(a, b) << '\n'; // gọi hàm add() với x=5 và y=6
>
>    return 0;
>} // b và a ra khỏi phạm vi và bị hủy ở đây
>```

Tham số `x` và `y` được tạo khi hàm `add` được gọi, chỉ có thể được nhìn thấy/sử dụng trong hàm `add` và bị hủy ở cuối hàm `add`. Biến `a` và `b` được tạo trong hàm `main`, chỉ có thể được nhìn thấy/sử dụng trong hàm `main` và bị hủy ở cuối hàm `main`.

**Phân tích chi tiết**

Để nâng cao hiểu biết của bạn về cách tất cả điều này hoạt động cùng nhau, chúng ta hãy theo dõi chi tiết hơn chương trình này. Các bước diễn ra theo thứ tự:

1. Chương trình bắt đầu chạy từ đầu hàm `main`.
2. Biến `a` của hàm `main` được tạo và gán giá trị `5`.
3. Biến `b` của hàm `main` được tạo và gán giá trị `6`.
4. Hàm `add` được gọi với các giá trị đối số là `5` và `6`.
5. Tham số `x` và `y` của hàm `add` được tạo và khởi tạo với các giá trị tương ứng là `5` và `6`.
6. Biểu thức `x + y` được tính toán để ra kết quả là `11`.
7. Hàm `add` sao chép giá trị `11` trở lại hàm gọi `main`.
8. Tham số `y` và `x` của hàm `add` bị hủy.
9. Hàm `main` in giá trị `11` ra console.
10. Hàm `main` trả về `0` cho hệ điều hành.
11. Biến `b` và `a` của hàm main bị hủy.

Lưu ý rằng nếu hàm `add` được gọi hai lần, thì các tham số `x` và `y` sẽ được tạo và hủy hai lần - một lần cho mỗi lần gọi. Trong một chương trình có nhiều hàm và các lệnh gọi

### **Sự tách biệt biến theo phạm vi hàm**

Trong ví dụ trên, rất dễ dàng để thấy rằng các biến `a` và `b` khác với các biến `x` và `y`.

Bây giờ hãy xem xét chương trình tương tự sau:

>```
>#include <iostream>
>
>int add(int x, int y) // x và y của add được tạo và bắt đầu nằm trong phạm vi ở đây
>{
>    // x và y của add chỉ nhìn thấy/sử dụng được trong hàm này
>    return x + y;
>} // y và x của add ra khỏi phạm vi và bị hủy ở đây
>
>int main()
>{
>    int x{ 5 }; // x của main được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
>    int y{ 6 }; // y của main được tạo, khởi tạo và bắt đầu nằm trong phạm vi ở đây
>
>    // x và y của main chỉ sử dụng được trong hàm này
>    std::cout << add(x, y) << '\n'; // calls function add() with x=5 and y=6
>
>    return 0;
>} // y và x của main ra khỏi phạm vi và bị hủy ở đây
>```

Trong ví dụ này, tất cả những gì chúng ta đã làm là thay đổi tên của các biến `a` và `b` bên trong hàm main thành `x` và `y`. Chương trình này biên dịch và chạy giống hệt nhau, mặc dù các hàm `main` và `add` đều có các biến được đặt tên là `x` và `y`. Tại sao điều này hoạt động?

Thứ nhất, chúng ta cần nhận ra rằng mặc dù các hàm `main` và `add` đều có các biến được đặt tên là `x` và `y`, nhưng các biến này là riêng biệt. Biến `x` và `y` trong hàm `main` không liên quan gì đến biến `x` và `y` trong hàm `add` - chúng chỉ trùng tên nhau mà thôi.

Thứ hai, khi bên trong hàm `main`, tên `x` và `y` tham chiếu đến các biến cục bộ `x` và `y` của main. Các biến đó chỉ có thể được nhìn thấy (và sử dụng) bên trong `main`. Tương tự, khi bên trong hàm `add`, tên `x` và `y` tham chiếu đến tham số hàm `x` và `y`, chúng chỉ có thể được nhìn thấy (và sử dụng) bên trong `add`.

Nói tóm lại, cả `add` và `main` đều không biết hàm kia có các biến cùng tên. Bởi vì phạm vi không chồng chéo, nên trình biên dịch luôn luôn rõ ràng biến `x` và `y` nào đang được tham chiếu tại bất kỳ thời điểm nào.

>**Ý chính**<br>
>Tên được sử dụng cho tham số hàm hoặc biến được khai báo trong thân hàm chỉ nhìn thấy được trong hàm khai báo chúng. Điều này có nghĩa là các biến cục bộ trong một hàm có thể được đặt tên mà không cần quan tâm đến tên của các biến trong các hàm khác. Điều này giúp các hàm hoạt động độc lập.

Chúng ta sẽ thảo luận thêm về phạm vi cục bộ và các loại phạm vi khác trong chương học sau.

### **Vị trí khai báo biến cục bộ**

Trong C++ hiện đại, cách thực hành tốt nhất là biến cục bộ bên trong thân hàm nên được khai báo càng gần lần sử dụng đầu tiên của chúng càng hợp lý:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x{};       // x được khai báo tại đây
>    std::cin >> x; // và được sử dụng tại đây
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y{};       // y được khai báo tại đây
>    std::cin >> y; // và được sử dụng tại đây
>
>    int sum{ x + y }; // sum có thể được khởi tạo với giá trị mong muốn
>    std::cout << "Tổng là: " << sum << '\n';
>
>    return 0;
>}
>```

Trong ví dụ trên, mỗi biến được khai báo ngay trước khi được sử dụng lần đầu tiên. Không cần quá khắt khe về điều này - nếu bạn muốn đổi chỗ dòng 5 và 6 thì cũng không sao.

>**Thực hành tốt nhất**<br>
>Khai báo biến cục bộ của bạn càng gần lần sử dụng đầu tiên của chúng càng hợp lý.

>**Ngoài lề**<br>
>Do những hạn chế của các trình biên dịch cũ, nguyên thủy hơn, ngôn ngữ C từng yêu cầu tất cả các biến cục bộ được khai báo ở đầu hàm. Chương trình C++ tương đương sử dụng phong cách đó sẽ trông như thế này:
>>```
>>#include <iostream>
>>
>>int main()
>>{
>>    int x{}, y{}, sum{}; // chúng được sử dụng như thế nào?
>>
>>    std::cout << "Nhập một số nguyên: ";
>>    std::cin >> x;
>>
>>    std::cout << "Nhập một số nguyên khác: ";
>>    std::cin >> y;
>>
>>    sum = x + y;
>>    std::cout << "Tổng là: " << sum << '\n';
>>
>>    return 0;
>>}
>>```
>
>Phong cách này không tối ưu vì một số lý do:
>- Mục đích sử dụng các biến này không rõ ràng tại thời điểm khai báo. Bạn phải quét qua toàn bộ hàm để xác định vị trí và cách sử dụng từng biến.
>- Giá trị khởi tạo dự định có thể không có sẵn ở đầu hàm (ví dụ: chúng ta không thể khởi tạo `sum` thành giá trị mong muốn vì chúng ta chưa biết giá trị của `x` và `y`).
>- Có thể có nhiều dòng giữa toán tử khởi tạo của biến và lần sử dụng đầu tiên của nó. Nếu chúng ta không nhớ giá trị nó được khởi tạo, chúng ta sẽ phải cuộn lại đầu hàm, điều này gây mất tập trung.
>
>Giới hạn này đã được dỡ bỏ trong tiêu chuẩn ngôn ngữ C99.

### **Giới thiệu về đối tượng tạm thời** 

Một **đối tượng tạm thời** (còn được gọi là **đối tượng ẩn danh**) là một đối tượng không tên do trình biên dịch tạo ra để lưu trữ giá trị tạm thời.

Có nhiều cách khác nhau để tạo ra các giá trị tạm thời, nhưng đây là một cách phổ biến:

>```
>#include <iostream>
>
>int getValueFromUser()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int input{};
>    std::cin >> input;
>
>    return input; // trả về giá trị của input cho hàm gọi
>}
>
>int main()
>{
>    std::cout << getValueFromUser() << '\n'; // giá trị trả về được lưu trữ ở đâu?
>
>    return 0;
>}
>```

Trong chương trình trên, hàm `getValueFromUser()` trả về giá trị được lưu trữ trong biến cục bộ `input` cho hàm gọi. Bởi vì `input` sẽ bị hủy ở cuối hàm, nên hàm gọi nhận được một bản sao của giá trị để nó có giá trị có thể sử dụng ngay cả sau khi `input` bị hủy.

Nhưng giá trị được sao chép lại cho hàm gọi được lưu trữ ở đâu? Chúng tôi chưa khai báo bất kỳ biến nào trong `main()`. Câu trả lời là giá trị trả về được lưu trữ trong một **đối tượng tạm thời**. Đối tượng tạm thời này sau đó được truyền cho `std::cout` để in ra.

**Đặc điểm của đối tượng tạm thời**
- Đối tượng tạm thời không có phạm vi (điều này hợp lý, vì phạm vi là thuộc tính của một định danh, và đối tượng tạm thời không có định danh).
- Đối tượng tạm thời bị hủy ở cuối biểu thức đầy đủ trong đó chúng được tạo. Do đó, đối tượng tạm thời được tạo để chứa giá trị trả về của `getValueFromUser()` bị hủy sau khi `std::cout << getValueFromUser() << '\n'` thực thi.
- Trong trường hợp một đối tượng tạm thời được sử dụng để khởi tạo một biến, việc khởi tạo xảy ra trước khi hủy đối tượng tạm thời.

**Cải tiến của C++ hiện đại**

Trong C++ hiện đại (đặc biệt là từ **C++17**), trình biên dịch có nhiều thủ thuật để tránh tạo các đối tượng tạm thời ở những nơi trước đây nó cần phải tạo. Trong ví dụ trên, vì giá trị trả về của `getValueFromUser()` được xuất ra ngay lập tức, trình biên dịch có thể bỏ qua việc tạo và hủy đối tượng tạm thời trong `main()`, và sử dụng giá trị trả về của `getValueFromUser()` để khởi tạo trực tiếp tham số của toán tử `<<`.
