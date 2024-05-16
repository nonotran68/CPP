## **Bài 1.11: <u>Phát triển chương trình đầu tiên của bạn</u>**

### **Giới thiệu**

Các bài học trước đã giới thiệu rất nhiều thuật ngữ và khái niệm mà chúng ta sẽ sử dụng trong hầu hết mọi chương trình được tạo. Trong bài học này, chúng ta sẽ hướng dẫn bạn từng bước về quá trình tích hợp các kiến thức này vào chương trình đơn giản đầu tiên của mình.

### **"Nhân đôi"**

Trước tiên, hãy tạo một chương trình yêu cầu người dùng nhập một số nguyên, đợi người dùng nhập số nguyên, sau đó thông báo cho họ biết kết quả của phép nhân `2` với số đó. Chương trình sẽ tạo ra đầu ra sau (giả sử tôi nhập `4`):
>`Enter an integer: 4`
>`Double that number is: 8`

Chúng ta sẽ giải quyết bài toán này như thế nào? Theo từng bước.

>**Thực hành tốt**
>
>Lập trình viên mới thường cố gắng viết toàn bộ chương trình cùng một lúc, sau đó sẽ bị choáng ngợp khi gặp nhiều lỗi. Chiến lược tốt hơn là thêm từng phần một, đảm bảo nó có thể biên dịch và kiểm tra nó. Sau đó, khi bạn chắc chắn nó hoạt động, hãy chuyển sang phần tiếp theo.

Chúng ta sẽ áp dụng chiến lược đó ở đây. Khi chúng ta thực hiện từng bước, hãy gõ (không sao chép/dán) từng chương trình vào trình soạn thảo mã của bạn, biên dịch và chạy nó.

Đầu tiên, ta sẽ tạo một dự án mới.

Bây giờ chúng ta hãy bắt đầu với một số bộ khung cơ bản. Chúng ta biết mình sẽ cần một hàm `main()` (vì tất cả các chương trình C++ đều phải có một hàm), vì vậy nếu IDE của bạn không tạo ra một hàm trống khi bạn tạo một dự án mới, hãy tạo một hàm:

>```
>int main()
>{
>    return 0;
>}
>```

Chúng ta biết mình sẽ cần xuất văn bản ra console và lấy văn bản từ bàn phím của người dùng, vì vậy chúng ta cần `#include <iostream>` để truy cập vào `std::cout` và `std::cin`.

>```
>#include <iostream>
>
>int main()
>{
>    return 0;
>}
>```

Bây giờ hãy thông báo cho người dùng rằng chúng ta cần họ nhập một số nguyên:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    return 0;
>}
>```

Lúc này, chương trình của bạn sẽ tạo ra kết quả này:

>`Enter an integer:`

và sau đó kết thúc.



Tiếp theo, chúng ta sẽ lấy đầu vào của người dùng. Chúng ta sẽ sử dụng `std::cin` và toán tử `>>` để lấy đầu vào của người dùng. Nhưng chúng ta cũng cần định nghĩa một biến để lưu trữ đầu vào đó để sử dụng sau này.

>```
>#include <iostream>
>
>int main() // Lưu ý: chương trình này có lỗi ở đâu đó
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ }; // Định nghĩa biến num là một biến kiểu số nguyên
>    std::cin >> num; // Lấy giá trị số nguyên từ bàn phím của người dùng
>
>    return 0;
>}
>```

Đã đến lúc biên dịch chương trình của chúng ta, và rồi...<br>
Ố ồ, đây là những gì tác giả nhận được trên Visual Studio 2017

>```
>1>------ Build started: Project: Double, Configuration: Release Win32 ------
>1>Double.cpp
>1>c:\vcprojects\double\double.cpp(8): error C2678: binary '<<': no operator found which takes a left-hand operand of type 'std::istream' (or there is no acceptable conversion)
>1>c:\vcprojects\double\double.cpp: note: could be 'built-in C++ operator<<(bool, int)'
>1>c:\vcprojects\double\double.cpp: note: while trying to match the argument list '(std::istream, int)'
>1>Done building project "Double.vcxproj" -- FAILED.
>========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
>```

Ôi chao! Chúng ta đã gặp lỗi biên dịch!

Trước tiên, vì chương trình đã biên dịch được trước khi chúng ta thực hiện cập nhật mới nhất này, và bây giờ không biên dịch được nữa, nên lỗi chắc chắn phải nằm trong đoạn mã vừa thêm (dòng 7 và 8). Điều đó giúp giảm đáng kể lượng mã cần kiểm tra để tìm lỗi. Dòng 7 khá đơn giản (chỉ là định nghĩa biến), vì vậy lỗi có thể không nằm ở đó. Điều đó khiến dòng 8 trở thành thủ phạm có khả năng nhất.

Thứ hai, thông báo lỗi này không dễ đọc. Nhưng hãy cùng phân tích một số yếu tố chính: Trình biên dịch đang thông báo cho chúng ta rằng nó gặp lỗi ở dòng 8. Điều đó có nghĩa là lỗi thực sự có thể nằm ở dòng 8 hoặc có thể là dòng trước đó, điều này củng cố đánh giá trước đó của chúng ta. Tiếp theo, trình biên dịch đang thông báo cho bạn rằng nó không thể tìm thấy toán tử '<<' nào có toán hạng bên trái kiểu std::istream (đó là kiểu của std::cin). Nói cách khác, toán tử << không biết phải làm gì với std::cin, vì vậy lỗi có thể nằm ở cách chúng ta sử dụng std::cin hoặc cách chúng ta sử dụng toán tử <<.

Bạn có thấy lỗi chưa? Nếu chưa, hãy dành một chút thời gian và xem liệu bạn có thể tìm thấy nó không.

Đây là chương trình chứa mã đã sửa:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num; // std::cin sử dụng toán tử >>, không phải toán tử <<!
>
>    return 0;
>}
>```

Bây giờ chương trình sẽ được biên dịch và chúng ta có thể kiểm tra nó. Chương trình sẽ đợi bạn nhập một số, vì vậy hãy nhập `4`. Đầu ra sẽ trông như thế này:



>`Enter an integer: 4`


Gần xong rồi! Bước cuối cùng là nhân đôi số đó.

Khi hoàn thành bước cuối cùng này, chương trình của chúng ta sẽ biên dịch và chạy thành công, tạo ra đầu ra mong muốn.

Có (ít nhất) 3 cách để chúng ta có thể thực hiện điều này. Hãy cùng đi từ tệ nhất đến tốt nhất.

#### *<u>Giải pháp không tốt:</u>*

>```
>#include <iostream>
>
>// Phiên bản tệ nhất
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    num = num * 2; // Nhân đôi giá trị của num, sau đó gán lại giá trị đó cho num
>
>    std::cout << "Double that number is: " << num << '\n';
>
>    return 0;
>}
>```

**Giải thích:**

Trong giải pháp này, chúng ta sử dụng một biểu thức để nhân `num` với `2`, sau đó gán lại giá trị đó cho `num`. Từ thời điểm đó trở đi, `num` sẽ chứa giá trị được nhân đôi của chúng ta.

**Tại sao đây là giải pháp tồi:**

- Mất tính minh bạch: Trước khi thực hiện câu lệnh gán, `num` chứa giá trị nhập vào của người dùng. Sau khi gán, nó chứa một giá trị khác. Điều này gây nhầm lẫn.
- Ghi đè dữ liệu người dùng: Chúng ta ghi đè lên giá trị nhập vào của người dùng bằng cách gán một giá trị mới cho biến `num`. Do đó, nếu sau này chúng ta muốn mở rộng chương trình để thực hiện một thao tác khác với giá trị nhập vào đó (ví dụ: nhân ba giá trị nhập vào của người dùng), thì giá trị đó đã bị mất.

#### *<u>Giải pháp tương đối tốt:</u>*

>```
>#include <iostream>
>
>// Phiên bản ít tệ hơn
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    int doublenum{ num * 2 }; // Định nghĩa một biến mới và khởi tạo nó với num * 2
>    std::cout << "Double that number is: " << doublenum << '\n'; // Sau đó in giá trị của biến đó ở đây
>
>    return 0;
>}
>```

**Giải thích:**

Giải pháp này khá dễ đọc và hiểu, đồng thời giải quyết cả hai vấn đề gặp phải trong giải pháp tồi tệ nhất.

**Nhược điểm:**

Nhược điểm chính ở đây là chúng ta đang định nghĩa một biến mới (làm tăng độ phức tạp) để lưu trữ một giá trị mà chúng ta chỉ sử dụng một lần. Chúng ta có thể làm tốt hơn thế.



#### *<u>Giải pháp được ưu tiên</u>*

>```
>#include <iostream>
>
>// Phiên bản được ưu tiên
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    std::cout << "Double that number is: " <<  num * 2 << '\n'; // Sử dụng biểu thức để nhân num * 2 tại thời điểm chúng ta sẽ in ra nó
>
>    return 0;
>}
>```

**Giải thích:**

Đây là giải pháp được ưu tiên nhất. Khi `std::cout` thực thi, biểu thức `num * 2` sẽ được tính toán và kết quả sẽ là giá trị gấp đôi của `num`. Giá trị đó sẽ được in ra. Bản thân giá trị trong `num` sẽ không bị thay đổi, vì vậy chúng ta có thể sử dụng lại nó sau này nếu muốn.

Phiên bản này là giải pháp tham khảo của chúng tôi.

>**Lưu ý của tác giả**
>
>Mục tiêu đầu tiên và quan trọng nhất của lập trình là khiến chương trình hoạt động. Một chương trình không hoạt động sẽ vô dụng bất kể được viết tốt đến đâu.
>
>Tuy nhiên, có một câu nói mà tôi rất tâm đắc: "Bạn phải viết một chương trình một lần để biết cách bạn nên viết nó ngay từ đầu." Điều này nói lên rằng giải pháp tốt nhất thường không hiển nhiên, và các giải pháp đầu tiên của chúng ta cho các vấn đề thường không tốt như chúng có thể.
>
>Khi chúng ta tập trung vào việc tìm cách để làm cho chương trình hoạt động, thì việc đầu tư nhiều thời gian vào mã mà chúng ta thậm chí không biết có giữ lại không là không hợp lý. Vì vậy, chúng tôi sử dụng các phím tắt. Chúng tôi bỏ qua những thứ như xử lý lỗi và chú thích. Chúng tôi rải mã gỡ lỗi xuyên suốt giải pháp của mình để giúp chúng tôi chẩn đoán các vấn đề và tìm lỗi. Chúng tôi học hỏi khi thực hiện - những thứ chúng tôi nghĩ có thể hoạt động thì hóa ra lại không, và chúng tôi phải quay lại và thử một cách tiếp cận khác.
>
>Kết quả cuối cùng là các giải pháp ban đầu của chúng tôi thường không được cấu trúc tốt, mạnh mẽ (chống lỗi), dễ đọc hoặc ngắn gọn. Vì vậy, một khi chương trình của bạn hoạt động, công việc của bạn thực sự chưa hoàn thành (trừ khi chương trình chỉ sử dụng một lần/bỏ đi). Bước tiếp theo là dọn dẹp mã của bạn. Điều này bao gồm các việc như: xóa (hoặc chú thích) mã tạm thời/gỡ lỗi, thêm chú thích, xử lý các trường hợp lỗi, định dạng mã của bạn và đảm bảo tuân theo các quy trình thực hành tốt nhất. Và thậm chí sau đó, chương trình của bạn có thể không đơn giản như nó có thể - có lẽ có logic trùng lặp có thể được hợp nhất, hoặc nhiều câu lệnh có thể được kết hợp, hoặc các biến không cần thiết, hoặc hàng ngàn điều nhỏ nhặt khác có thể được đơn giản hóa. Quá nhiều lập trình viên mới tập trung vào tối ưu hóa hiệu suất trong khi họ nên tối ưu hóa khả năng bảo trì.
>
>Rất ít giải pháp được trình bày trong các hướng dẫn này có kết quả tuyệt vời ngay từ lần đầu tiên. Thay vào đó, chúng là kết quả của quá trình tinh chỉnh liên tục cho đến khi không thể tìm thấy gì khác để cải thiện. Và trong nhiều trường hợp, người đọc vẫn tìm thấy nhiều điều khác để gợi ý cải tiến!
>
>Tất cả những điều này thực sự để nói: đừng thất vọng nếu/khi các giải pháp của bạn không được tối ưu hóa tuyệt vời ngay từ đầu. Điều đó là bình thường. Hoàn thiện trong lập trình là một quá trình lặp lại (yêu cầu lặp lại nhiều lần).

>**Lưu ý của tác giả**
>
>Một điều nữa: Bạn có thể đang nghĩ, "C++ có quá nhiều quy tắc và khái niệm. Làm thế nào để nhớ tất cả những thứ này?".
>
>Câu trả lời ngắn gọn: Bạn không cần nhớ. C++ là sự kết hợp giữa việc sử dụng những gì bạn đã biết và việc tra cứu cách thực hiện phần còn lại.
>
>Khi bạn đọc trang web này lần đầu tiên, hãy tập trung ít hơn vào việc ghi nhớ các chi tiết cụ thể, mà nhiều hơn vào việc hiểu những gì có thể. Sau đó, khi bạn cần triển khai một cái gì đó trong chương trình bạn đang viết, bạn có thể quay lại đây (hoặc đến một trang web tham khảo) và làm mới lại kiến thức của mình về cách thực hiện.
