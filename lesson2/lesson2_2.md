## **Bài 2.2: <u>Hàm trả về giá trị (value-returning functions)</u>**

Xét đoạn chương trình sau:

>```
>#include <iostream>
>
>int main() {
>    // Nhận giá trị từ người dùng
>    std::cout << "Nhập một số nguyên: ";
>    int num{};
>    std::cin >> num;
>
>    // In ra giá trị gấp đôi
>    std::cout << num << " nhân đôi là: " << num * 2 << '\n';
>
>    return 0;
>}
>```

Chương trình này được cấu thành từ hai phần: Đầu tiên, chúng ta nhận giá trị từ người dùng. Sau đó, chúng ta thông báo cho người dùng giá trị đó nhân đôi là bao nhiêu.

Mặc dù chương trình này đủ đơn giản để không cần chia thành nhiều hàm, nhưng nếu chúng ta muốn chia tách thì sao? Nhận giá trị số nguyên từ người dùng là một công việc được xác định rõ ràng mà chương trình của chúng ta cần thực hiện, do đó nó sẽ là một ứng cử viên tốt cho một hàm.

Vì vậy, hãy viết một chương trình để thực hiện việc này:

>```
>// Chương trình này không hoạt động
>#include <iostream>
>
>void getValueFromUser() {
>    std::cout << "Nhập một số nguyên: ";
>    int input{};
>    std::cin >> input;
>}
>
>int main() {
>    getValueFromUser(); // Yêu cầu người dùng nhập dữ liệu
>
>    int num{}; // Làm thế nào để lấy giá trị từ getValueFromUser() và sử dụng nó để khởi tạo biến này?
>
>    std::cout << num << " nhân đôi là: " << num * 2 << '\n';
>
>    return 0;
>}
>```

Mặc dù chương trình này là một nỗ lực giải quyết tốt, nhưng nó không hoàn toàn hoạt động.

Khi hàm `getValueFromUser` được gọi, người dùng được yêu cầu nhập một số nguyên như mong đợi. Nhưng giá trị họ nhập vào sẽ bị mất khi `getValueFromUser` kết thúc và quyền điều khiển trở lại `main`. Biến num không bao giờ được khởi tạo bằng giá trị người dùng nhập vào, do đó chương trình luôn in ra kết quả `0`.

### **Giá trị trả về**

Khi bạn viết một hàm do người dùng định nghĩa, bạn có thể xác định xem hàm của bạn có trả về giá trị cho trình gọi hay không. Để trả về giá trị cho trình gọi, cần hai điều.

#### **1. Kiểu trả về của hàm (Return Type):**

Thứ nhất, hàm của bạn phải chỉ định loại giá trị sẽ được trả về. Điều này được thực hiện bằng cách đặt kiểu trả về của hàm, là kiểu được xác định trước tên hàm. Trong ví dụ trên, hàm `getValueFromUser` có kiểu trả về là `void` (có nghĩa là không có giá trị nào được trả về cho trình gọi), và hàm `main` có kiểu trả về là `int` (nghĩa là một giá trị kiểu `int` sẽ được trả về cho trình gọi). Lưu ý rằng điều này không xác định chính xác giá trị cụ thể được trả về - nó chỉ xác định kiểu của giá trị sẽ được trả về.

>**Bài học liên quan:**<br>
>Chúng ta sẽ khám phá thêm về các hàm trả về `void` trong bài học tiếp theo **(2.3 - Hàm Void (hàm không trả về giá trị)).**

#### **2. Sử dụng câu lệnh return (Return Statement)**

Thứ hai, bên trong hàm sẽ trả về một giá trị, chúng ta sử dụng câu lệnh `return` để chỉ định giá trị cụ thể được trả về cho trình gọi. Giá trị cụ thể được trả về từ một hàm được gọi là **giá trị trả về** của hàm. Khi câu lệnh `return` được thực thi, hàm thoát ngay lập tức và giá trị trả về được sao chép từ hàm trở lại hàm gọi. Quá trình này được gọi là **trả về theo giá trị (return by value).**



Ví dụ:<br>
Hãy xem một hàm đơn giản trả về một giá trị số nguyên và một chương trình mẫu gọi hàm đó:

>```
>#include <iostream>
>
>// int là kiểu trả về
>// Kiểu trả về int có nghĩa là hàm sẽ trả về một giá trị số nguyên nào đó cho trình gọi (giá trị cụ thể không được chỉ định ở đây)
>int returnFive() {
>    // Câu lệnh return chỉ định giá trị cụ thể sẽ được trả về
>    return 5; // Trả về giá trị cụ thể 5 cho hàm gọi.
>}
>
>int main() {
>    std::cout << returnFive() << '\n'; // In 5
>    std::cout << returnFive() + 2 << '\n'; // In 7
>
>    returnFive(); // Không sao: giá trị 5 được trả về, nhưng bị bỏ qua vì main() không làm gì với nó
>
>    return 0;
>}
>```
Hãy thận trọng khi sử dụng các đoạn mã.
Khi chạy, chương trình này in:

>`5`\
>`7`

#### **Thứ tự thực thi:**


- Quá trình thực thi bắt đầu từ đầu hàm `main`.
- Trong câu lệnh đầu tiên, lệnh gọi hàm `returnFive` được đánh giá, dẫn đến việc hàm `returnFive` được gọi.
- Hàm `returnFive` trả về giá trị cụ thể là `5` hàm gọi (hàm `main`), sau đó giá trị này được in ra console thông qua `std::cout`.
- Trong lệnh gọi hàm thứ hai, lệnh gọi hàm `returnFive` được đánh giá, dẫn đến việc hàm `returnFive` được gọi lại lần nữa. Hàm `returnFive` trả về giá trị `5` cho hàm gọi. Biểu thức `5 + 2` được tính toán để tạo ra kết quả `7`, sau đó được in ra console thông qua `std::cout`.
- Trong câu lệnh thứ ba, hàm `returnFive` được gọi lại, dẫn đến việc giá trị `5` được trả về cho hàm gọi. Tuy nhiên, hàm `main` không làm gì với giá trị trả về này, vì vậy không có gì khác xảy ra (giá trị trả về bị bỏ qua).

>**Lưu ý:**<br>
>Giá trị trả về sẽ không được in ra trừ khi trình gọi gửi chúng đến console thông qua `std::cout`. Trong trường hợp cuối cùng ở trên, giá trị trả về không được gửi đến `std::cout`, vì vậy không có gì được in ra.

>**Mẹo:**<br>
>Khi một hàm được gọi trả về giá trị, hàm gọi nó có thể quyết định sử dụng giá trị đó trong một biểu thức hoặc câu lệnh (ví dụ: sử dụng nó để khởi tạo biến hoặc gửi nó đến `std::cout`) hoặc bỏ qua nó (bằng cách không làm gì khác). Nếu hàm gọi bỏ qua giá trị trả về, nó sẽ bị loại bỏ (không có gì được thực hiện với nó).

### **Giải quyết bài toán thách thức đặt ra ở đầu bài**

Giờ đây, với những kiến thức vừa học, chúng ta có thể sửa chữa chương trình được giới thiệu ở đầu bài:

>```
>#include <iostream>
>int getValueFromUser() { // Hàm này hiện trả về một giá trị kiểu số nguyên
>    std::cout << "Enter an integer: ";
>    int input {};
>    std::cin >> input;
>    return input; // Trả về giá trị người dùng nhập cho hàm gọi
>}
>int main() {
>    int num { getValueFromUser() }; // Khởi tạo num bằng giá trị trả về của getValueFromUser()
>    std::cout << num << " doubled is: " << num * 2 << '\n';
>
>    return 0;
>}
>```

**Giải thích:**

Khi chương trình này thực thi, câu lệnh đầu tiên trong `main` sẽ tạo một biến int có tên `num`. Khi chương trình khởi tạo `num`, nó sẽ thấy có một lệnh gọi hàm `getValueFromUser()`, do đó chương trình sẽ thực thi hàm đó. Hàm `getValueFromUser` yêu cầu người dùng nhập giá trị, sau đó trả giá trị đó về cho trình gọi (`main`). Giá trị trả về này được sử dụng làm giá trị khởi tạo cho biến `num`.

Hãy tự biên dịch chương trình này và chạy nó vài lần để kiểm tra xem nó hoạt động chính xác hay không.


### **Xem xét lại hàm `main()`:**

Bây giờ bạn đã có những công cụ khái niệm để hiểu cách thức hoạt động thực sự của hàm `main`. Khi chương trình được thực thi, hệ điều hành sẽ gọi hàm `main`. Sau đó, quá trình thực thi nhảy đến đầu của `main`. Các câu lệnh trong `main` được thực thi tuần tự. Cuối cùng, `main` trả về một giá trị kiểu số nguyên (thường là `0`), và chương trình của bạn kết thúc. Giá trị trả về từ `main` đôi khi được gọi là **mã trạng thái (status code, còn được gọi là mã thoát (exit code) hoặc hiếm khi gọi là mã trả về (return code))**, vì nó được sử dụng để báo hiệu chương trình có chạy thành công hay không.

Theo định nghĩa, mã trạng thái `0` có nghĩa là chương trình đã chạy thành công.

>**Thực hành:**
>
>Hàm main của bạn nên trả về giá trị 0 nếu chương trình chạy bình thường.

Mã trạng thái khác 0 thường được sử dụng để báo hiệu lỗi (mặc dù điều này đúng trên hầu hết các hệ điều hành, nhưng về mặt lý thuyết, nó không đảm bảo tính di động).

>**Đối với người đọc nâng cao:**
>
>Chuẩn C++ chỉ định nghĩa ý nghĩa của 3 mã trạng thái: `0`, `EXIT_SUCCESS` và `EXIT_FAILURE`. `0` và `EXIT_SUCCESS` đều có nghĩa là chương trình chạy thành công. `EXIT_FAILURE` có nghĩa là chương trình không chạy thành công.
>
>`EXIT_SUCCESS` và `EXIT_FAILURE` là các macro tiền xử lý được định nghĩa trong tiêu đề <cstdlib>:
>
>>```
>>#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE
>>
>>int main()
>>{
>>    return EXIT_SUCCESS;
>>}
>>```

Nếu bạn muốn tối đa hóa khả năng di động, bạn chỉ nên sử dụng `0` hoặc `EXIT_SUCCESS` để báo hiệu kết thúc thành công, hoặc `EXIT_FAILURE` để báo hiệu kết thúc không thành công.

>**Lưu ý:**
>
>**C++** không cho phép gọi hàm main() một cách trực tiếp.

>**Ngoài lề:**
>
>**C** cho phép gọi `main()` trực tiếp, vì vậy một số trình biên dịch **C++**
> sẽ cho phép điều này vì lý do tương thích.

Hiện tại, bạn cũng nên định nghĩa hàm `main()` ở cuối tệp mã của bạn, bên dưới các hàm khác, và tránh gọi nó trực tiếp.

### **Một hàm trả về giá trị mà không trả về giá trị sẽ tạo ra hành vi bất định.**

Một hàm trả giá trị được thiết kế để cung cấp một giá trị cụ thể (số nguyên, chuỗi ký tự, đối tượng, ...) cho đoạn mã gọi hàm đó. Một hàm là hàm trả về giá trị nếu kiểu trả về là bất kỳ thứ gì ngoại trừ `void`. Kiểu trả về của hàm xác định loại dữ liệu mà nó sẽ trả về. Các kiểu trả về phổ biến gồm `int` (số nguyên), `double` (số thực), `string` (chuỗi ký tự), và các kiểu dữ liệu do bạn tự định nghĩa.

Một hàm trả về giá trị phải trả về một giá trị của kiểu đó (sử dụng câu lệnh `return`), nếu không sẽ tạo ra hành vi bất định.

>**Nội dung liên quan**
>
>Chúng tôi thảo luận về **hành vi bất định** trong **[bài học 1.6 - Biến chưa khởi tạo và hành vi bất định](../lesson1/lesson1_6.ipynb).**

**Hành vi bất định:**

>```
>#include <iostream>
>
>int getValueFromUserUB() { // Hàm này được khai báo để trả về một số nguyên
>  std::cout << "Nhập một số nguyên: ";
>  int input;
>  std::cin >> input;
>
>  // Lưu ý: Không có câu lệnh return!
>}
>
>int main() {
>  int num = getValueFromUserUB(); // Cố gắng sử dụng giá trị trả về
>
>  std::cout << num << " nhân đôi là: " << num * 2 << std::endl;
>
>  return 0;
>}
>```

Trong ví dụ này, hàm `getValueFromUserUB` được khai báo để trả về một số nguyên, nhưng nó thiếu câu lệnh `return` để cung cấp giá trị đó. Việc thiếu sót này dẫn đến hành vi bất định:
- Chương trình có thể bị lỗi hoặc tạo ra kết quả không mong đợi.
- Giá trị được gán cho `num` trong `main` trở nên bất định, dẫn đến lỗi tiềm ẩn khi sử dụng nó trong các phép tính.

May mắn thay, nhiều trình biên dịch hiện đại sẽ cảnh báo khi gặp hàm được khai báo để trả về giá trị nhưng thiếu `return`. Những cảnh báo này giúp bạn phát hiện lỗi và ngăn chặn hành vi bất định.

Trong hầu hết các trường hợp, trình biên dịch sẽ phát hiện nếu bạn quên trả về một giá trị. Tuy nhiên, trong một số trường hợp phức tạp, trình biên dịch có thể không thể xác định một cách chính xác liệu hàm của bạn có trả về một giá trị hay không trong tất cả các trường hợp, vì vậy bạn không nên phụ thuộc vào điều này.

>**Lưu ý**
>- Luôn sử dụng return trong các hàm trả giá trị. Điều này giúp mã của bạn dễ hiểu, dự đoán được và ít lỗi hơn.

### **Hàm `main()` sẽ ngầm định `return 0;` nếu lệnh return không được cấp**

Hàm `main` là một trường hợp đặc biệt. Nếu `main` không có câu lệnh `return` rõ ràng, mặc định nó sẽ trả về `0`. Tuy nhiên, nên thành lập thói quen sử dụng `return` với giá trị cụ thể trong `main` để thể hiện ý định và duy trì tính nhất quán với các hàm khác (mà sẽ gây ra hành vi bất định nếu thiếu `return`).


### **Hàm chỉ có thể trả về một giá trị:**

Một hàm trả về giá trị chỉ có thể trả về một giá trị duy nhất cho người gọi mỗi lần nó được gọi.

Lưu ý rằng giá trị được cung cấp trong câu lệnh `return` không cần phải là literal -- nó có thể là kết quả của bất kỳ biểu thức hợp lệ nào, bao gồm biến hoặc thậm chí là một lời gọi đến một hàm trả về giá trị khác. Trong ví dụ của hàm `getValueFromUser()` ở trên, chúng ta đã trả về một biến `input`, chứa giá trị mà người dùng nhập vào.

Mặc dù các hàm thường chỉ trả về một giá trị duy nhất, nhưng có những kỹ thuật trong lập trình (như truyền đối số theo tham chiếu hoặc trả về cấu trúc) cho phép bạn truyền tải dữ liệu phức tạp hơn. Những khái niệm này sẽ được đề cập trong các bài học sau.



### **Ý nghĩa của giá trị trả về của hàm:**

Ý nghĩa của giá trị trả về bởi một hàm được xác định bởi tác giả của hàm đó. Một số hàm sử dụng giá trị trả về như mã trạng thái, để báo hiệu chúng thành công hay thất bại. Các hàm khác trả về một giá trị được tính toán hoặc lựa chọn. Một số hàm khác không trả về gì (chúng ta sẽ xem các ví dụ về những hàm này trong bài học tiếp theo).

Do có nhiều khả năng khác nhau, nên tốt nhất là bạn nên ghi chú hàm của mình bằng một bình luận cho biết ý nghĩa của các giá trị trả về. Ví dụ:

>```
>// Hàm yêu cầu người dùng nhập giá trị
>// Giá trị trả về là số nguyên được người dùng nhập từ bàn phím
>int getValueFromUser()
>{
>  std::cout << "Nhập một số nguyên: ";
>  int input{};
>  std::cin >> input;
>
>  return input; // trả về giá trị người dùng nhập cho chương trình gọi
>}
>```

### **Sử dụng lại hàm**

Bây giờ chúng ta có thể minh họa một ví dụ hay về việc sử dụng lại hàm. Xem xét chương trình sau:

>```
>#include <iostream>
>
>int main()
>{
>  int x{};
>  std::cout << "Nhập một số nguyên: ";
>  std::cin >> x;
>
>  int y{};
>  std::cout << "Nhập một số nguyên: ";
>  std::cin >> y;
>
>  std::cout << x << " + " << y << " = " << x + y << '\n';
>
>  return 0;
>}
>```

Mặc dù chương trình này hoạt động, nhưng nó hơi thừa. Thực tế, chương trình này vi phạm một trong những nguyên tắc cốt lõi của lập trình tốt: **Đừng Lặp Lại Chính Mình** (thường được viết tắt là **DRY - Don't Repeat Yourself).**

Tại sao mã lặp lại là không tốt? Nếu chúng ta muốn thay đổi văn bản `"Nhập một số nguyên:"` thành thứ khác, chúng ta sẽ phải cập nhật nó ở hai vị trí. Và nếu chúng ta muốn khởi tạo 10 biến thay vì 2 thì sao? Điều đó sẽ tạo ra rất nhiều mã thừa (khiến chương trình của chúng ta dài hơn và khó hiểu hơn), và tạo ra nhiều chỗ cho lỗi đánh máy.

Hãy cập nhật chương trình này để sử dụng hàm `getValueFromUser` mà chúng ta đã phát triển ở trên:

>```
>#include <iostream>
>
>int getValueFromUser()
>{
>  std::cout << "Nhập một số nguyên: ";
>  int input{};
>  std::cin >> input;
>
>  return input;
>}
>
>int main()
>{
>  int x{ getValueFromUser() }; // gọi getValueFromUser lần đầu
>  int y{ getValueFromUser() }; // gọi getValueFromUser lần thứ hai
>
>  std::cout << x << " + " << y << " = " << x + y << '\n';
>
>  return 0;
>}
>```

Chương trình này tạo ra đầu ra sau:
>```
>Nhập một số nguyên: 5
>Nhập một số nguyên: 7
>5 + 7 = 12
>```

Trong chương trình này, chúng ta gọi `getValueFromUser` hai lần, một lần để khởi tạo biến `x` và một lần để khởi tạo biến `y`. Điều đó giúp chúng ta tránh việc sao chép mã để lấy đầu vào của người dùng và giảm thiểu khả năng mắc lỗi. Một khi chúng ta biết `getValueFromUser` hoạt động, chúng ta có thể gọi nó nhiều lần theo ý muốn.

Đây là bản chất của **lập trình mô-đun**: khả năng viết một hàm, kiểm tra nó, đảm bảo nó hoạt động và sau đó biết rằng chúng ta có thể sử dụng lại nó nhiều lần tùy thích và nó sẽ tiếp tục hoạt động (miễn là chúng ta không sửa đổi hàm - tại thời điểm đó chúng ta sẽ phải kiểm tra lại).

>**Thực hành tốt nhất: Tránh lặp lại mã (DRY)**<br>
>**Nguyên tắc <u>DRY</u> (Don't Repeat Yourself - Tránh lặp lại chính mình):**
>- Nếu bạn cần thực hiện một tác vụ nhiều hơn một lần, hãy cân nhắc cách sửa đổi mã để loại bỏ càng nhiều sự trùng lặp càng tốt.
>- Biến có thể được sử dụng để lưu trữ kết quả của các phép tính cần sử dụng nhiều lần (để chúng ta không phải lặp lại phép tính).
>- Hàm có thể được sử dụng để xác định một chuỗi các lệnh mà chúng ta muốn thực thi nhiều hơn một lần.
>- Vòng lặp (sẽ được đề cập trong một chương sau) có thể được sử dụng để thực thi một câu lệnh nhiều hơn một lần.

>**Lưu ý:**<br>
>DRY là một nguyên tắc hướng dẫn, không phải quy tắc tuyệt đối. Quá chia nhỏ mã thành các phần quá nhỏ có thể ảnh hưởng đến khả năng hiểu tổng thể của chương trình.
>Ngược lại của **DRY** là **WET (“Write everything twice” - Viết mọi thứ hai lần).**
