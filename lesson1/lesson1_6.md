## **Bài 1.6: <u>Biến chưa được khởi tạo trong C/C++</u>**

**Không giống như một số ngôn ngữ lập trình khác, C/C++ không tự động khởi tạo hầu hết các biến thành một giá trị nhất định (chẳng hạn như 0).** Khi một biến chưa được khởi tạo được cấp một địa chỉ bộ nhớ để lưu trữ dữ liệu, giá trị mặc định của biến đó là bất kỳ giá trị "rác" (garbage value) nào có sẵn trong địa chỉ bộ nhớ đó! Biến chưa được gán một giá trị đã biết (thông qua khởi tạo hoặc gán) được gọi là **biến chưa được khởi tạo** (**uninitialized variable**).

>**Thuật ngữ**\
>Nhiều người đọc mong đợi các thuật ngữ "được khởi tạo" (**initialized**) và "chưa được khởi tạo" (**uninitialized**) là hoàn toàn đối lập, nhưng chúng không hẳn như vậy! Trong ngôn ngữ thông thường, "được khởi tạo" có nghĩa là đối tượng được cung cấp một giá trị ban đầu tại thời điểm khai báo. "Chưa được khởi tạo" có nghĩa là đối tượng chưa được gán một giá trị đã biết (bằng bất kỳ phương thức nào, bao gồm cả gán). Do đó, một đối tượng không được khởi tạo nhưng sau đó được gán một giá trị thì không còn là chưa được khởi tạo (bởi vì nó đã được cung cấp một giá trị đã biết).

>**Tóm tắt**
>- Khởi tạo = Đối tượng được cung cấp một giá trị đã biết tại thời điểm khai báo.
>- Gán = Đối tượng được cung cấp một giá trị đã biết sau thời điểm khai báo.
>- Chưa được khởi tạo = Đối tượng chưa được cung cấp một giá trị đã biết.

Liên quan đến điều đó, hãy xem xét định nghĩa biến này:
>`int x;`

Trong bài học **1.4 - Gán và khởi tạo biến**, chúng tôi đã lưu ý rằng khi không cung cấp trình khởi tạo, biến sẽ được khởi tạo mặc định. Trong hầu hết các trường hợp (chẳng hạn như trường hợp này), khởi tạo mặc định không thực hiện khởi tạo thực tế. Do đó, chúng ta có thể nói `x` là chưa được khởi tạo. Chúng ta tập trung vào kết quả (đối tượng chưa được cung cấp một giá trị đã biết), chứ không phải quá trình.

>**Ngoài lề**\
>Sự thiếu khởi tạo này là một tối ưu hóa hiệu suất được thừa hưởng từ C, quay lại thời điểm máy tính còn chậm. Hãy tưởng tượng trường hợp bạn sẽ đọc 100.000 giá trị từ một file. Trong trường hợp đó, bạn có thể tạo 100.000 biến, sau đó điền chúng bằng dữ liệu từ file.
>
>Nếu C++ khởi tạo tất cả các biến đó với các giá trị mặc định khi tạo, điều này sẽ dẫn đến 100.000 lần khởi tạo (có thể chậm) và mang lại lợi ích rất ít (vì bạn đang ghi đè lên các giá trị đó dù sao).
>
>Hiện tại, bạn luôn nên khởi tạo các biến của mình vì chi phí thực hiện việc đó không đáng kể so với lợi ích. Khi bạn đã thoải mái hơn với ngôn ngữ, có thể có một số trường hợp nhất định bạn bỏ qua việc khởi tạo vì mục đích tối ưu hóa. Nhưng điều này luôn được thực hiện một cách chọn lọc và cố ý.

**Sử dụng giá trị của các biến chưa được khởi tạo có thể dẫn đến kết quả không mong đợi.** Hãy xem xét chương trình ngắn sau đây:
>```
>#include <iostream>
>
>int main()
>{
>    // Định nghĩa một biến integer có tên x
>    int x; // Biến này chưa được khởi tạo vì chúng tôi chưa gán giá trị cho nó
>
>    // In giá trị của x lên màn hình
>    std::cout << x << '\n'; // Ai biết chúng ta sẽ nhận được gì, vì x chưa được khởi tạo
>
>    return 0;
>}
>```

Trong trường hợp này, máy tính sẽ gán một số bộ nhớ chưa sử dụng cho `x`. Sau đó, nó sẽ gửi giá trị nằm trong vị trí bộ nhớ đó tới `std::cout`, giá trị này sẽ in giá trị (được hiểu là số nguyên). Nhưng nó sẽ in ra giá trị gì? Câu trả lời là “ai biết được!”, và câu trả lời có thể (hoặc không) thay đổi mỗi khi bạn chạy chương trình. Khi tác giả chạy chương trình này trong Visual Studio, `std::cout` đã in giá trị `7177728` một lần và `5277592` tiếp theo. Hãy thoải mái biên dịch và chạy chương trình (máy tính của bạn sẽ không nổ đâu).


Hầu hết các trình biên dịch hiện đại sẽ cố gắng phát hiện xem một biến có đang được sử dụng mà chưa được gán giá trị hay không. Nếu phát hiện 
được, chúng thường sẽ đưa ra cảnh báo hoặc lỗi thời gian biên dịch. Ví dụ, biên dịch chương trình trên trong Visual Studio sẽ tạo ra cảnh báo sau:

>`c:\VCprojects\test\test.cpp(11) : warning C4700: uninitialized local variable 'x' used`

Đối với `g++`:
>```
>exp1_6a.cpp: In function ‘int main()’:
>exp1_6a.cpp:9:23: error: ‘x’ is used uninitialized [-Werror=uninitialized]
>    9 |     std::cout << x << '\n'; // Ai biết chúng ta sẽ nhận được
> gì, vì x chưa được khởi tạo
>      |                       ^~~~
>exp1_6a.cpp:6:9: note: ‘x’ was declared here
>    6 |     int x; // Biến này chưa được khởi tạo vì chúng tôi chưa 
>gán giá trị cho nó
>      |         ^
>cc1plus: all warnings being treated as errors
>```

Nếu trình biên dịch của bạn không cho phép biên dịch và chạy chương trình trên (ví dụ: vì nó coi vấn đề này là lỗi), thì đây là một giải pháp khả thi để giải quyết vấn đề này:

>```
>#include <iostream>
>
>void doNothing(int&) // Đừng lo lắng về '&' là gì lúc này, chúng tôi chỉ sử dụng nó để đánh lừa trình biên dịch nghĩ rằng biến x được sử dụng
>{
>}
>
>int main()
>{
>    // Khai báo biến nguyên x
>    int x; // Biến này chưa được khởi tạo
>
>    doNothing(x); // Đánh lừa trình biên dịch nghĩ rằng chúng ta đang gán giá trị cho biến này
>
>    // In giá trị của x lên màn hình (ai biết được chúng ta sẽ nhận được gì, vì x chưa được khởi tạo).
>    std::cout << x << '\n';
>
>    return 0;
>}

Sử dụng biến chưa được khởi tạo là một trong những lỗi phổ biến nhất mà lập trình viên mới mắc phải và không may, nó cũng có thể là một trong những lỗi khó gỡ lỗi nhất (vì chương trình vẫn có thể chạy tốt nếu biến chưa được khởi tạo tình cờ được gán vào một vùng nhớ có giá trị hợp lý, chẳng hạn như 0).

Đây là lý do chính cho nguyên tắc hay thực hành tốt nhất là *“luôn khởi tạo các biến của bạn”*.


### **Hành vi bất định (Undefined Behavior)**


Sử dụng giá trị từ một biến chưa được khởi tạo là ví dụ đầu tiên của chúng tôi về hành vi bất định (undefined behavior). Hành vi bất định (thường được viết tắt là UB) là kết quả của việc thực thi đoạn mã mà hành vi của nó không được xác định rõ ràng bởi ngôn ngữ C++. Trong trường hợp này, ngôn ngữ C++ không có bất kỳ quy tắc nào quy định điều gì sẽ xảy ra nếu bạn sử dụng giá trị của một biến chưa được gán giá trị đã biết. Do đó, nếu bạn thực sự làm điều này, hành vi bất định sẽ xảy ra.

Mã triển khai hành vi bất định có thể biểu hiện bất kỳ triệu chứng nào sau đây:
- Chương trình của bạn tạo ra các kết quả khác nhau mỗi lần chạy.
- Chương trình của bạn luôn tạo ra cùng một kết quả không chính xác.
- Chương trình của bạn hoạt động không nhất quán (đôi khi tạo ra kết quả chính xác, đôi khi không).
- Chương trình của bạn dường như hoạt động nhưng tạo ra kết quả không chính xác sau này trong chương trình.
- Chương trình của bạn bị treo, ngay lập tức hoặc sau đó.
- Chương trình của bạn hoạt động trên một số trình biên dịch nhưng không hoạt động trên các trình biên dịch khác.
- Chương trình của bạn hoạt động cho đến khi bạn thay đổi một số đoạn mã khác dường như không liên quan.

>**Lưu ý của tác giả:**\
>Hành vi bất định giống như một hộp sôcôla. Bạn không bao giờ biết mình sẽ nhận được gì!

C++ chứa nhiều trường hợp có thể dẫn đến hành vi bất định nếu bạn không cẩn thận. Chúng tôi sẽ chỉ ra những điều này trong các bài học tương lai bất cứ khi nào chúng tôi gặp chúng. Hãy ghi nhớ những trường hợp này và đảm bảo bạn tránh chúng.

>**Nguyên tắc:**\
>Cẩn thận tránh tất cả các tình huống dẫn đến hành vi bất định, chẳng hạn như sử dụng biến chưa được khởi tạo.


### **Hành vi phụ thuộc trình biên dịch (Implementation-defined behavior) và hành vi không được chỉ định rõ ràng (Unspecified behavior)**



#### <u>*Hành vi phụ thuộc trình biên dịch:*</u>

- Đây là cách xử lý của một số cú pháp nhất định do trình biên dịch (compiler) quyết định.
- Các hành vi này phải nhất quán và được ghi nhận trong tài liệu của trình biên dịch, nhưng kết quả có thể khác nhau giữa các trình biên dịch khác nhau.
- **Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  std::cout << sizeof(int) << '\n'; // In ra kích thước bộ nhớ cần thiết cho một kiểu int
>  return 0;
>}
>```

    Trong hầu hết các hệ thống, đoạn code này sẽ in ra giá trị `4`, nhưng trên một số hệ thống khác, nó có thể in ra giá trị `2`. Điều này phụ thuộc vào cách trình biên dịch trên từng nền tảng phân bổ bộ nhớ cho kiểu dữ liệu `int`.




#### <u>*Hành vi không được chỉ định rõ ràng (Unspecified Behaviour):*</u>

- Giống với hành phụ thuộc trình biên dịch, hành vi không chỉ định rõ ràng phụ thuộc vào cách trình biên dịch xử lý, nhưng không yêu cầu trình biên dịch phải ghi nhận lại hành vi đó.
Ví dụ: 
- Thứ tự đánh giá (evaluate) các biểu thức con, thứ tự đánh giá các đối số truyền vào hàm là không được chỉ định rõ ràng, đây là unspecified behaviour.

#### *Tại sao nên tránh*

Cả hai loại hành vi lỗi này đều có thể dẫn đến việc chương trình hoạt động không như mong đợi khi được biên dịch trên một trình biên dịch khác, hoặc thậm chí trên cùng một trình biên dịch nếu bạn thay đổi các cài đặt dự án ảnh hưởng đến cách thức hoạt động của trình biên dịch.
