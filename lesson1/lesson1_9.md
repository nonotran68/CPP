## **Bài 1.9: <u>Giới thiệu về Literal và Toán tử</u>**

### **Literal (Giá trị nguyên văn)**:

Hãy xem xét hai câu lệnh sau:

>`std::cout << "Hello world!";`\
>`int x { 5 };`

`"Hello world!"` và `5` là gì? Chúng là **literal** (giá trị nguyên văn). **Literal** (giá trị nguyên văn) là một giá trị cố định được đưa trực tiếp vào mã nguồn. **Literal** và **biến** đều có một giá trị (và một kiểu dữ liệu). Khác với biến (có giá trị có thể được thiết lập và thay đổi thông qua khởi tạo và gán tương ứng), giá trị của **literal** là **cố định** (`5` luôn luôn là `5`). Đây là lý do tại sao **literal** được gọi là hằng giá trị.

Để làm nổi bật hơn sự khác biệt giữa literal và biến, chúng ta hãy xem xét chương trình ngắn này:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 5 << '\n'; // in ra giá trị của một literal
>
>    int x { 5 };
>    std::cout << x << '\n'; // in ra giá trị của một biến
>    return 0;
>}
>```

Ở dòng 5, chúng ta đang in giá trị `5` ra console. Khi trình biên dịch biên dịch đoạn này, nó sẽ tạo ra code khiến `std::cout` in ra giá trị `5`. Giá trị `5` này được biên dịch vào trong file thực thi và có thể được sử dụng trực tiếp.

Ở dòng 7, chúng ta đang tạo một biến tên `x` và khởi tạo nó với giá trị `5`. Trình biên dịch sẽ tạo ra code sao chép giá trị literal `5` vào bất kỳ vị trí bộ nhớ nào được cấp cho `x`. Ở dòng 8, khi chúng ta in `x`, trình biên dịch sẽ tạo ra code khiến `std::cout` in ra giá trị tại vị trí bộ nhớ của x (có giá trị là `5`).

Do đó, cả hai câu lệnh in đều thực hiện cùng một tác vụ (in ra giá trị `5`). Nhưng trong trường hợp của literal, giá trị `5` được in ra trực tiếp. Trong trường hợp của biến, giá trị `5` phải được lấy từ bộ nhớ mà biến đó biểu diễn.

Điều này cũng giải thích tại sao literal là hằng giá trị trong khi biến có thể thay đổi. Giá trị của literal được đặt trực tiếp vào file thực thi và bản thân file thực thi không thể thay đổi sau khi được tạo. Giá trị của biến được đặt trong bộ nhớ và giá trị của bộ nhớ có thể thay đổi trong khi file thực thi đang chạy.

>**Lưu ý quan trọng:**
>- Literal là các giá trị được đưa trực tiếp vào mã nguồn. Các giá trị này thường xuất hiện trực tiếp trong code thực thi (trừ khi chúng được tối ưu hóa).
>- Đối tượng và biến đại diện cho các vị trí bộ nhớ chứa các giá trị. Các giá trị này có thể được truy xuất theo yêu cầu.

>**Nội dung liên quan:**
>Chúng ta sẽ tìm hiểu sâu hơn về literal trong bài 5.2 -- Literal.



### **Toán tử trong C++**

#### <u>Toán tử</u>



Trong toán học, một **phép toán (operation)** là một phép thực hiện tính toán liên quan đến 0 hoặc nhiều giá trị đầu vào (gọi là **toán hạng - operands**) tạo ra một giá trị mới (gọi là **giá trị đầu ra - output value**). Phép toán cụ thể cần thực hiện được biểu thị bằng một ký hiệu gọi là **toán tử** (operator).

Ví dụ: từ nhỏ chúng ta đều học được rằng 2 + 3 bằng 5. Trong trường hợp này, các literal 2 và 3 là toán hạng và ký hiệu + là toán tử cho biết chúng ta cần thực hiện phép cộng toán học trên các toán hạng để tạo ra giá trị mới 5.





#### <u>Toán tử trong C++</u>

Trong C++, các phép toán cũng hoạt động tương tự như vậy. Ví dụ:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 1 + 2 << '\n';
>
>    return 0;
>}
>```

Trong chương trình này, các literal `1` và `2` là toán hạng cho toán tử cộng (`+`), toán tử này tạo ra giá trị đầu ra `3`. Giá trị đầu ra này sau đó được in ra console. Trong C++, giá trị đầu ra của một phép toán thường được gọi là **giá trị trả về (return value).**

Bạn có thể đã khá quen thuộc với các toán tử số học tiêu chuẩn thường được sử dụng trong toán học, bao gồm cộng (`+`), trừ (`-`), nhân (`*`), và chia (`/`). Trong C++, gán (`=`) cũng là một toán tử, cũng như toán tử đưa vào (`<<`), trích xuất (`>>`) và so sánh bằng (`==`). Trong khi hầu hết các toán tử có biểu tượng làm tên (ví dụ: `+`, hoặc `==`), thì cũng có một số toán tử là từ khóa (ví dụ: `new`, `delete` và `throw`).

**Số lượng toán hạng**

Số lượng toán hạng mà một toán tử lấy làm đầu vào được gọi là **arity** (ngôi) của toán tử. Ít người biết từ này có nghĩa là gì, vì vậy đừng sử dụng nó trong cuộc trò chuyện và mong đợi mọi người hiểu bạn đang nói về điều gì. Toán tử trong C++ có bốn loại arity khác nhau:
- **Một ngôi (Unary)**: Toán tử một ngôi tác động lên một toán hạng. Ví dụ về toán tử một ngôi là toán tử `-`. Ví dụ, với `-5`, toán tử `-` lấy toán hạng theo nghĩa đen `5` và đảo ngược dấu của nó để tạo ra giá trị đầu ra mới `-5`.
- **Hai ngôi (Binary)**: Toán tử hai ngôi tác động lên hai toán hạng (thường được gọi là trái và phải, vì toán hạng trái xuất hiện ở bên trái của toán tử và toán hạng phải xuất hiện ở bên phải của toán tử). Ví dụ về toán tử hai ngôi là toán tử `+`. Ví dụ, với `3 + 4`, toán tử + lấy toán hạng trái `3` và toán hạng phải `4` và áp dụng phép cộng toán học để tạo ra giá trị đầu ra mới `7`. Toán tử chèn (`<<`) và trích xuất (`>>`) là các toán tử hai ngôi, lấy `std::cout` hoặc `std::cin` ở bên trái và giá trị cần xuất ra hoặc biến để nhập vào ở bên phải.
- **Ba ngôi (Ternary)**: Toán tử ba ngôi tác động lên ba toán hạng. Chỉ có một toán tử này trong C++ (toán tử điều kiện), chúng ta sẽ tìm hiểu sau.
- **Không ngôi (Nullary)**: Toán tử không ngôi tác động lên 0 toán hạng. Cũng chỉ có một toán tử này trong C++ (toán tử `throw`), chúng ta cũng sẽ tìm hiểu sau.

Lưu ý rằng một số toán tử có nhiều hơn một nghĩa tùy thuộc vào cách chúng được sử dụng. Ví dụ, toán tử `-` có hai ngữ cảnh. Nó có thể được sử dụng ở dạng một ngôi để đảo ngược dấu của một số (ví dụ: để chuyển đổi `5` thành `-5` hoặc ngược lại), hoặc nó có thể được sử dụng ở dạng hai ngôi để thực hiện phép trừ (ví dụ: `4 - 3`).







### **Liên kết toán tử**

Các toán tử có thể được liên kết với nhau sao cho kết quả đầu ra của một toán tử có thể được sử dụng làm đầu vào cho một toán tử khác. Ví dụ, với biểu thức: `2 * 3 + 4`, toán tử nhân được thực hiện trước tiên, và chuyển đổi toán hạng trái `2` và toán hạng phải `3` thành giá trị trả về `6` (trở thành toán hạng trái cho toán tử cộng). Tiếp theo, toán tử cộng được thực hiện, và chuyển đổi toán hạng trái `6` và toán hạng phải `4` thành giá trị mới `10`.

Chúng ta sẽ nói thêm về thứ tự thực thi các toán tử khi chúng ta đi sâu vào chủ đề toán tử. Hiện tại, chỉ cần biết rằng các toán tử số học được thực hiện theo cùng thứ tự như trong toán học chuẩn: **Đầu tiên là dấu ngoặc, tiếp theo là lũy thừa, sau đó là nhân và chia, sau đó là cộng và trừ**. Thứ tự này đôi khi được viết tắt là **PEMDAS**, hoặc được mở rộng thành cụm từ **“Please Excuse My Dear Aunt Sally”** (Vui lòng tha lỗi cho dì Sally thân mến của tôi).





### **Giá trị trả về và tác dụng phụ**

Hầu hết các toán tử trong C++ chỉ sử dụng toán hạng của chúng để tính toán một giá trị trả về. <br>
Ví dụ, `-5` tạo ra giá trị trả về `-5` và `2 + 3` tạo ra giá trị trả về `5`. Có một vài toán tử không tạo ra giá trị trả về (chẳng hạn như `delete` và `throw`). Chúng ta sẽ đề cập đến những điều này sau.

Một số toán tử có các hành vi bổ sung. Một toán tử (hoặc hàm) có một số tác động quan sát được vượt ra ngoài việc tạo ra giá trị trả về được gọi là có **tác dụng phụ** (hay **hiệu ứng lề**) (**side effect**). Ví dụ, khi `x = 5` được đánh giá, toán tử gán có tác dụng phụ là gán giá trị `5` cho biến `x`. Giá trị thay đổi của `x` có thể quan sát được (ví dụ: bằng cách in giá trị của `x`) ngay cả sau khi toán tử thực hiện xong. `std::cout << 5` có tác dụng phụ là in `5` ra console. Chúng ta có thể quan sát thấy thực tế là `5` đã được in ra console ngay cả sau khi `std::cout << 5` đã thực hiện xong.

Các toán tử có tác dụng phụ thường được gọi vì hành vi của tác dụng phụ chứ không phải vì giá trị trả về (nếu có) mà các toán tử đó tạo ra.

>**Thuật ngữ** <br>
>Trong ngôn ngữ thông dụng, thuật ngữ **“tác dụng phụ”** thường được sử dụng để chỉ một kết quả phụ (thường là tiêu cực hoặc không mong đợi) của một điều gì đó khác xảy ra (chẳng hạn như dùng thuốc). Ví dụ, một tác dụng phụ phổ biến của việc uống kháng sinh đường uống là tiêu chảy. Như vậy, chúng ta thường nghĩ về tác dụng phụ như những thứ chúng ta muốn tránh, hoặc những thứ không liên quan đến mục tiêu chính.
>
>Trong C++, thuật ngữ **“tác dụng phụ”** có một ý nghĩa khác: nó là một tác động quan sát được của một toán tử hoặc hàm vượt ra ngoài việc tạo ra giá trị trả về.
>
>Vì phép gán có tác dụng quan sát được là thay đổi giá trị của một đối tượng, nên đây được coi là một tác dụng phụ. Chúng ta sử dụng một số toán tử nhất định (ví dụ: toán tử gán) chủ yếu vì các tác dụng phụ của chúng. Trong những trường hợp như vậy, tác dụng phụ vừa có lợi vừa có thể dự đoán được (và giá trị trả về thường là thứ không cần thiết).

>**Đối với người đọc nâng cao** <br>
>Đối với các toán tử mà chúng ta gọi chủ yếu để lấy giá trị trả về của chúng (ví dụ: toán tử `+` hoặc toán tử `*`), thì giá trị trả về của chúng thường là rõ ràng (ví dụ: tổng hoặc tích của các toán hạng).
>
>Đối với các toán tử mà chúng ta gọi chủ yếu vì các tác dụng phụ của chúng (ví dụ: toán tử `=` hay toán tử `<<`), thì không phải lúc nào cũng rõ ràng giá trị trả về của chúng là gì (nếu có). Ví dụ, bạn mong đợi giá trị trả về của `x = 5` là gì?
>
>Cả toán tử `=` và toán tử `<<` (khi được sử dụng để xuất giá trị ra console) đều trả về toán hạng trái của chúng. Do đó, `x = 5` trả về `x` và `std::cout << 5` trả về `std::cout`. Điều này được thực hiện để các toán tử này có thể được **liên kết** (**chaining**).
>
>Ví dụ, biểu thức `x = y = 5` được tính toán như `x = (y = 5)`. Đầu tiên `y = 5` gán giá trị `5` cho biến `y`. Sau đó phép toán này trả về giá trị của `y`, giá trị này sau đó có thể được gán cho biến `x`.
>
>Biểu thức `std::cout << "Hello " << "world"` được tính toán như `(std::cout << "Hello ") << "world!"`. Đầu tiên, nó in `"Hello "` ra console. Phép toán này trả về `std::cout`, sau đó nó có thể được sử dụng để in `"world!"` ra console.
>
>Chúng ta sẽ thảo luận thêm về thứ tự thực thi các toán tử trong bài **6.1 - Ưu tiên toán tử và tính kết hợp (Operator precedence and associativity).**
