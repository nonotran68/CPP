## **Bài 4.10: <u>Giới thiệu về câu lệnh `if`</u>**

Hãy tưởng tượng bạn đang đi chợ và bạn cùng phòng nói với bạn, *"nếu họ có bán dâu tây giảm giá, hãy mua một ít"*. Đây là một câu lệnh điều kiện, nghĩa là bạn chỉ thực hiện một hành động *("mua một ít")* khi điều kiện *("họ có bán dâu tây giảm giá")* là đúng.

Những câu lệnh điều kiện như vậy rất phổ biến trong lập trình, vì chúng cho phép chúng ta triển khai hành vi theo điều kiện vào các chương trình của mình. Loại câu lệnh điều kiện đơn giản nhất trong C++ được gọi là câu lệnh `if`. Câu lệnh `if` cho phép chúng ta chỉ thực thi một (hoặc nhiều) dòng lệnh nếu một điều kiện nào đó là đúng.

**Cấu trúc đơn giản nhất của câu lệnh `if` như sau:**
>```
>if (condition) true_statement;
>```

Để dễ đọc, cấu trúc này thường được viết thành:
>```
>if (condition)
>    true_statement;
>```

**Điều kiện** (còn được gọi là **biểu thức điều kiện**) là một biểu thức được đánh giá thành giá trị Boolean (`true` hoặc `false`).

Nếu điều kiện của câu lệnh `if` được đánh giá thành giá trị Boolean `true`, thì `true_statement` được thực thi. Ngược lại, nếu điều kiện được đánh giá thành giá trị Boolean `false`, thì `true_statement` sẽ bị bỏ qua.



### **Ví dụ về chương trình sử dụng câu lệnh `if`**

**Xét chương trình sau:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>
>    return 0;
>}
>```


**Đây là kết quả chạy của chương trình:**
>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>```

Chúng ta hãy xem xét chi tiết cách hoạt động của chương trình này.

Đầu tiên, người dùng nhập một số nguyên. Sau đó, điều kiện `x == 0` được đánh giá. Toán tử so sánh bằng (`==`) được sử dụng để kiểm tra xem hai giá trị có bằng nhau hay không. Toán tử `==` trả về `true` nếu các toán hạng bằng nhau và `false` nếu chúng không bằng nhau. Vì `x` có giá trị `0` và `0 == 0` là `true`, biểu thức này được đánh giá thành `true`.

Do điều kiện được đánh giá thành `true`, câu lệnh tiếp theo được thực thi, in ra `"Giá trị bằng 0"`.

Đây là một lần chạy khác của chương trình này:
>```
>Nhập một số nguyên: 5
>```

Trong trường hợp này, `x == 0` được đánh giá thành `false`. Câu lệnh tiếp theo bị bỏ qua, chương trình kết thúc và không in thêm gì nữa.

>**Cảnh báo**<br>
>Câu lệnh `if` chỉ có thể thực thi có điều kiện một câu lệnh duy nhất. Chúng ta sẽ thảo luận về cách thực thi có điều kiện nhiều câu lệnh trong bài học 8.2 - Câu lệnh if và khối lệnh (If statements and blocks).

### **Câu lệnh `if-else`**

Trong ví dụ trên, nếu chúng ta muốn thông báo cho người dùng rằng số họ nhập vào khác `0` thì sao?

**Chúng ta có thể viết như thế này:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>    if (x != 0)
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

**Hoặc như thế này:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    bool zero { (x == 0) };
>    if (zero)
>        std::cout << "Giá trị bằng 0\n";
>    if (!zero)
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

Cả hai chương trình này đều phức tạp hơn mức cần thiết. Thay vào đó, chúng ta có thể sử dụng một dạng khác của câu lệnh `if` được gọi là `if-else`. Cấu trúc của `if-else` như sau:
>```
>if (condition)
>    true_statement;
>else
>    false_statement;
>```

Nếu điều kiện được đánh giá thành giá trị Boolean `true`, thì `true_statement` được thực thi. Ngược lại, `false_statement` sẽ được thực thi.

**Hãy sửa đổi chương trình trước đó của chúng ta để sử dụng `if-else`:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>    else
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

**Bây giờ chương trình của chúng ta sẽ tạo ra đầu ra sau:**
>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>Nhập một số nguyên: 5
>Giá trị khác 0
>```

### **Nối tiếp các câu lệnh `if` (chaining `if` statements)**

Trong lập trình, đôi khi chúng ta cần kiểm tra nhiều điều kiện theo thứ tự. Để thực hiện điều này, chúng ta có thể sử dụng các câu lệnh `if` (hoặc `if-else`) nối tiếp nhau.

**Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  std::cout << "Nhập một số nguyên: ";
>  int x;
>  std::cin >> x;
>
>  if (x > 0) {
>    std::cout << "Giá trị dương\n";
>  } else if (x < 0) {
>    std::cout << "Giá trị âm\n";
>  } else {
>    std::cout << "Giá trị bằng 0\n";
>  }
>
>  return 0;
>}
>```

**Đây là kết quả chạy của chương trình trong một vài trường hợp:**
>```
>Nhập một số nguyên: 4
>Giá trị dương
>```

>```
>Nhập một số nguyên: -3
>Giá trị âm
>```

>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>```

**Giải thích:**

Toán tử so sánh `<` được dùng để kiểm tra xem một giá trị có nhỏ hơn giá trị khác hay không. Tương tự, toán tử so sánh `>` dùng để kiểm tra xem một giá trị có lớn hơn giá trị khác hay không. Cả hai toán tử này đều trả về giá trị **Boolean** (`true` hoặc `false`).
Chương trình có thể in ra nhiều kết quả khác nhau phụ thuộc vào điều kiện được đáp ứng.



**Lưu ý:** Bạn có thể nối tiếp các câu lệnh `if` nhiều lần tùy thuộc vào số điều kiện cần kiểm tra. Cách sử dụng này sẽ được minh họa rõ hơn trong phần bài tập ở cuối bài.


### **Giá trị trả về Boolean và câu lệnh `if`**

Trong bài học trước ([**4.9 - Giá trị logic**](lesson4_9.ipynb)), chúng ta đã viết một chương trình sử dụng hàm để trả về giá trị Boolean:
>```
>#include <iostream>
>
>// Kiểm tra xem x và y có bằng nhau không (true nếu bằng, false nếu khác)
>bool isEqual(int x, int y)
>{
>    return x == y; // Toán tử == trả về true nếu x bằng y, và false nếu khác
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y {};
>    std::cin >> y;
>
>    std::cout << std::boolalpha; // In giá trị Boolean dưới dạng true hoặc false
>
>    std::cout << x << " và " << y << " có bằng nhau không? ";
>    std::cout << isEqual(x, y); // Sẽ trả về true hoặc false
>
>    std::cout << '\n';
>
>    return 0;
>}
>```

Bây giờ, chúng ta hãy cải thiện chương trình này bằng cách sử dụng câu lệnh `if`:
>```
>#include <iostream>
>
>// Kiểm tra xem x và y có bằng nhau không (true nếu bằng, false nếu khác)
>bool isEqual(int x, int y)
>{
>    return x == y; // Toán tử == trả về true nếu x bằng y, và false nếu khác
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y {};
>    std::cin >> y;
>
>    if (isEqual(x, y))
>        std::cout << x << " và " << y << " bằng nhau\n";
>    else
>        std::cout << x << " và " << y << " không bằng nhau\n";
>
>    return 0;
>}
>```

**Giải thích:**
- Biểu thức điều kiện trong trường hợp này đơn giản là việc gọi hàm `isEqual`, vốn sẽ trả về một giá trị Boolean.
- Chương trình kiểm tra giá trị trả về của hàm `isEqual` bằng câu lệnh `if`.
    - Nếu `isEqual` trả về `true` (nghĩa là `x` và `y` bằng nhau), dòng lệnh trong khối `if` sẽ được thực thi.
    - Ngược lại, nếu `isEqual` trả về `false` (nghĩa là `x` và `y` khác nhau), dòng lệnh trong khối `else` sẽ được thực thi.

**Ưu điểm:**
- Sử dụng câu lệnh `if` với hàm trả về giá trị Boolean giúp code dễ đọc và dễ hiểu hơn.
- Tách biệt logic kiểm tra điều kiện ra thành một hàm riêng, giúp code có tính mô-đun hơn và dễ dàng tái sử dụng.

**Chạy thử:**
>```
>Nhập một số nguyên: 5
>Nhập một số nguyên khác: 5
>5 và 5 bằng nhau
>```

>```
>Nhập một số nguyên: 6
>Nhập một số nguyên khác: 4
>6 và 4 không bằng nhau
>```

**Lưu ý:** Bất kỳ hàm nào trả về giá trị Boolean đều có thể được sử dụng trong biểu thức điều kiện của câu lệnh `if`.

### **Điều kiện không phải Boolean (Non-Boolean conditionals)**

Trong các ví dụ trước đó, điều kiện của câu lệnh `if` đều là các giá trị Boolean (`true` hoặc `false`), biến Boolean hoặc hàm trả về giá trị Boolean. Nhưng điều gì xảy ra nếu điều kiện là một biểu thức không được tính toán thành giá trị Boolean?

**Sẽ có phép chuyển đổi ngầm**

Trong trường hợp này, biểu thức điều kiện sẽ được chuyển đổi ngầm sang giá trị Boolean. Các quy tắc chuyển đổi như sau:
- Giá trị khác `0` được chuyển thành `true`.
- Giá trị bằng `0` được chuyển thành `false`.

**Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  if (4) // Không hợp lý nhưng dùng để minh họa
>    std::cout << "hi\n";
>  else
>    std::cout << "bye\n";
>
>  return 0;
>}
>```

Kết quả chạy sẽ in ra `"hi"` vì `4` là giá trị khác `0` nên được chuyển đổi thành `true`, khiến câu lệnh trong khối `if` được thực thi.

**Lưu ý:**
- Mặc dù cú pháp cho phép điều kiện không phải Boolean, nhưng đây thường không phải là cách viết code tốt.
- Sử dụng các biểu thức trả về giá trị Boolean rõ ràng sẽ giúp code dễ đọc và dễ hiểu hơn.
- Tránh sử dụng các phép chuyển đổi ngầm này trừ khi bạn hiểu rõ tác dụng của chúng và chắc chắn rằng chúng sẽ không gây ra lỗi.

    **Sử dụng điều kiện Boolean rõ ràng**
    >```
    >#include <iostream>
    >
    >int main() {
    >  int x = 4;
    >  if (x != 0) // Điều kiện rõ ràng
    >    std::cout << "x khác 0\n";
    >  else
    >    std::cout << "x bằng 0\n";
    >
    >  return 0;
    >}
    >```

    Trong đoạn code này, điều kiện `x != 0` rõ ràng hơn so với việc dựa vào phép chuyển đổi ngầm.

### **Câu lệnh `if` và early return (If-statements and early returns)**

**Early Return là gì?**

Trong lập trình, **early return** (trả về sớm) là một câu lệnh `return` xuất hiện bên trong một hàm nhưng không phải là dòng lệnh cuối cùng. Khi gặp early return, hàm sẽ dừng thực thi và trả về giá trị cho bên hàm gọi (caller) ngay lập tức, thay vì thực hiện đến hết hàm như thông thường.

Ví dụ về early return không cần thiết:
>```
>void print() {
>  std::cout << "A" << '\n';
>
>  return; // Hàm luôn trả về cho bên gọi tại đây
>
>  std::cout << "B" << '\n'; // Dòng này không bao giờ được in ra
>}
>```

Trong ví dụ này, vì `return;` luôn được thực thi trước, dòng `std::cout << "B" << '\n';` sẽ không bao giờ được thực hiện. Do đó, thay vì dùng early return không cần thiết, chúng ta có thể loại bỏ dòng `std::cout << "B" << '\n';` và lúc này return không còn là early return nữa.

**Sử dụng early return kết hợp với câu lệnh `if`:**

Tuy nhiên, khi kết hợp với câu lệnh `if`, early return trở thành một cách hữu ích để kiểm soát giá trị trả về của hàm dựa trên điều kiện.
>```
>#include <iostream>
>
>// Tính giá trị tuyệt đối của x
>int abs(int x) {
>  if (x < 0)
>    return -x; // Early return (chỉ khi x < 0)
>
>  return x;
>}
>
>int main() {
>  std::cout << abs(4) << '\n'; // In ra 4
>  std::cout << abs(-3) << '\n'; // In ra 3
>
>  return 0;
>}
>```

Khi gọi `abs(4)`, giá trị của `x` là `4`. Điều kiện `if (x < 0)` sai nên early return không được thực thi. Hàm trả về giá trị `x` (bằng `4`) cho bên gọi ở cuối hàm.

Khi gọi `abs(-3)`, giá trị của `x` là `-3`. Điều kiện `if (x < 0)` đúng nên early return được thực thi. Hàm trả về `-x` (bằng `3`) cho bên gọi tại thời điểm này.

Trước đây, việc sử dụng **early return** thường không được khuyến khích. Tuy nhiên, trong lập trình hiện đại, **early return** được chấp nhận rộng rãi hơn, đặc biệt khi chúng giúp đơn giản hóa hàm hoặc dừng hàm sớm do lỗi.

>**Bài học liên quan:**<br>
>Bài 8.11 - Break và Continue sẽ thảo luận chi tiết hơn về tranh cãi liên quan đến early return.\
>Bài 8.2 - Câu Lệnh if và Khối Lệnh sẽ tiếp tục khám phá về các câu lệnh if.

### **Bài tập**

**Câu hỏi #1:** Early return (trả về sớm) là gì và hoạt động như thế nào?
<details>
<summary><b>Đáp án:</b></summary>

Early return là một câu lệnh `return` xuất hiện bên trong một hàm nhưng không phải là dòng lệnh cuối cùng. Khi gặp early return, hàm sẽ dừng thực thi và trả về giá trị cho hàm gọi (caller) ngay lập tức, thay vì thực hiện đến hết hàm như thông thường.
</details>

**Câu hỏi #2:** Số nguyên tố là một số tự nhiên lớn hơn 1 chỉ chia hết cho 1 và chính nó. Viết chương trình yêu cầu người dùng nhập một số từ 0 đến 9 (bao gồm cả 0 và 9). Nếu người dùng nhập một số nguyên tố (2, 3, 5 hoặc 7), hãy in ra "The digit is prime" (Số này là số nguyên tố). Ngược lại, hãy in ra "The digit is not prime" (Số này không phải số nguyên tố). 
<details>
<summary><b>Gợi ý:</b></summary>
  
Sử dụng chuỗi các câu lệnh `if-else` để so sánh số người dùng nhập với các số nguyên tố và kiểm tra xem có khớp hay không.


</details>
<details>
<summary><b>Đáp án:</b></summary>

>```
>#include <iostream>
>
>bool isPrime(int x) {
>  if (x == 2) // Nếu người dùng nhập 2, đây là số nguyên tố
>    return true;
>  else if (x == 3) // Nếu người dùng nhập 3, đây là số nguyên tố
>    return true;
>  else if (x == 5) // Nếu người dùng nhập 5, đây là số nguyên tố
>    return true;
>  else if (x == 7) // Nếu người dùng nhập 7, đây là số nguyên tố
>    return true;
>
>  return false; // Nếu người dùng không nhập 2, 3, 5, 7, thì số này không phải số nguyên tố
>}
>
>int main() {
>  std::cout << "Enter a number 0 through 9: ";
>  int x;
>  std::cin >> x;
>
>  if (isPrime(x))
>    std::cout << "The digit is prime\n";
>  else
>    std::cout << "The digit is not prime\n";
>
>  return 0;
>}
>```

>**Đối với người đọc nâng cao:**<br>
>Nếu hàm `isPrime()` ở trên có vẻ hơi dài dòng/lặp lại thì đúng là như vậy. Chúng ta có thể viết `isPrime()` gọn hơn và hiệu quả hơn bằng cách sử dụng một số khái niệm sẽ được giải thích trong các bài học tiếp theo.
>
>- Sử dụng toán tử logic **OR** (`||`) ([Bài 6.7 - Toán tử logic]()):
>
>>```
>>bool isPrime(int x) {
>>  return x == 2 || x == 3 || x == 5 || x == 7; // Nếu người dùng nhập 2 hoặc 3 hoặc 5 hoặc 7, đây là số nguyên tố
>>}
>>```
>
>- Sử dụng câu lệnh `switch` ([Bài 8.5 - Giới thiệu về câu lệnh switch]()):
>
>>```
>>bool isPrime(int x) {
>>  switch (x) {
>>    case 2: // Nếu người dùng nhập 2
>>    case 3: // Hoặc nếu người dùng nhập 3
>>    case 5: // Hoặc nếu người dùng nhập 5
>>    case 7: // Hoặc nếu người dùng nhập 7
>>      return true; // Thì đây là số nguyên tố
>>  }
>>
>>  return false; // Ngược lại thì số này không phải số nguyên tố
>>}
>>```
</details>


**Câu hỏi #3**: Làm thế nào để giảm độ dài của đoạn code sau (không thay đổi định dạng)?
>```
>#include <iostream>
>
>bool isAllowedToTakeFunRide()
>{
>  std::cout << "How tall are you? (cm)\n";
>
>  double height{};
>  std::cin >> height;
>
>  if (height >= 140.0)
>    return true;
>  else
>    return false;
>}
>
>int main()
>{
>  if (isAllowedToTakeFunRide())
>    std::cout << "Have fun!\n";
>  else
>    std::cout << "Sorry, you're too short.\n";
>
>  return 0;
>}
>```
<details>
    <summary><b>Đáp án:</b></summary>

Chúng ta không cần câu lệnh `if` trong `isAllowedToTakeFunRide()`. Biểu thức `height >= 140.0` được đánh giá thành thành giá trị `bool`, có thể được trả về trực tiếp.
>```
>bool isAllowedToTakeFunRide()
>{
>  std::cout << "How tall are you? (cm)\n";
>
>  double height{};
>  std::cin >> height;
>
>  return height >= 140.0;
>}
>```

Bạn không bao giờ cần câu lệnh `if` có dạng:
>```
>if (condition)
>  return true;
>else
>  return false;
>```

Bởi điều này có thể được thay thế bằng câu lệnh trả về `return condition`.

Tóm lại, khi biểu thức trả về giá trị `bool` (`true` hoặc `false`), bạn có thể trực tiếp trả về giá trị của biểu thức đó thay vì sử dụng câu lệnh `if` để kiểm tra và trả về `true` hoặc `false`.
</details>

