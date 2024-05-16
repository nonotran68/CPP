## **Bài 3.4: <u>Các chiến thuật gỡ lỗi cơ bản </u>**

Trong bài học trước, chúng ta đã khám phá một chiến lược để tìm ra vấn đề bằng cách chạy chương trình và sử dụng phỏng đoán để xác định vị trí của sự cố. Trong bài học này, chúng ta sẽ khám phá một số chiến thuật cơ bản để thực hiện những phỏng đoán đó và thu thập thông tin giúp tìm ra sự cố.

### **Chiến thuật gỡ lỗi #1: Ghi chú code**

**Ghi chú code (comment out code)** là một chiến thuật gỡ lỗi đơn giản nhưng hiệu quả giúp loại trừ những phần code không liên quan đến vấn đề đang gặp phải.

Hãy bắt đầu với một chiến thuật đơn giản. Nếu chương trình của bạn đang hiển thị hành vi lỗi, một cách để giảm thiểu lượng code bạn phải tìm kiếm là chú thích một phần code và xem sự cố có tiếp tục xảy ra hay không. Nếu sự cố vẫn không thay đổi, thì đoạn code được chú thích ra có thể không phải là nguyên nhân gây ra sự cố.

Hãy xem xét đoạn mã sau:
>```
>int main()
>{
>    getNames(); // yêu cầu người dùng nhập một loạt tên
>    doMaintenance(); // thực hiện một số công việc ngẫu nhiên
>    sortNames(); // sắp xếp chúng theo thứ tự bảng chữ cái
>    printNames(); // in danh sách tên đã được sắp xếp
>
>    return 0;
>}
>```

Giả sử chương trình này được cho là in ra các tên theo thứ tự bảng chữ cái mà lại in ra theo thứ tự ngược lại. Vấn đề ở đâu? Liệu `getNames` nhập tên không chính xác? Hay `sortNames` sắp xếp chúng theo thứ tự ngược? Hay `printNames` in chúng theo thứ tự ngược? Nó có thể là bất kỳ điều nào trong số những thứ đó. Nhưng chúng ta có thể nghi ngờ `doMaintenance` không liên quan gì đến vấn đề, vì vậy hãy bình luận nó ra.

**Có ba kết quả có thể xảy ra:**
- Nếu sự cố biến mất, thì `doMaintenance` phải là nguyên nhân gây ra sự cố và chúng ta nên tập trung sự chú ý vào đó.
- Nếu sự cố không thay đổi (xác suất cao hơn), thì chúng ta có thể hợp lý cho rằng `doMaintenance` không phải là lỗi và chúng ta có thể tạm thời loại trừ toàn bộ hàm khỏi quá trình tìm kiếm. Điều này không giúp chúng ta hiểu liệu vấn đề thực sự nằm trước hay sau lệnh gọi `doMaintenance`, nhưng nó giảm thiểu lượng code mà chúng ta phải xem xét sau đó.
- Nếu việc bình luận `doMaintenance` khiến sự cố chuyển sang một sự cố liên quan khác (ví dụ: chương trình ngừng in tên), thì có khả năng `doMaintenance` đang thực hiện một tác vụ hữu ích mà một số code khác phụ thuộc vào. Trong trường hợp này, chúng ta có thể không thể xác định liệu sự cố nằm trong `doMaintenance` hay ở nơi khác, vì vậy chúng ta có thể bỏ ghi chú cho `doMaintenance` và thử một cách tiếp cận khác.

>**Tóm tắt:**
>Cách thực hiện:
>1. Xác định vị trí xảy ra lỗi trong chương trình.
>2. Ghi chú một phần code nghi ngờ có liên quan đến lỗi.
>3. Chạy lại chương trình và quan sát kết quả.
>
>Kết quả có thể xảy ra:
>- *Vấn đề biến mất:* Phần code được ghi chú là nguyên nhân gây ra lỗi.
>- *Vấn đề vẫn tiếp tục:* Phần code được ghi chú không liên quan đến lỗi.
>- *Vấn đề thay đổi:* Phần code được ghi chú có thể đang thực hiện một tác vụ quan trọng ảnh hưởng đến các phần code khác.

>**Chú ý:**<br>
>Trong khi sử dụng chú thích code để gỡ lỗi, bạn cần lưu ý đến những điều sau:
>- **Không quên bỏ ghi chú code sau khi gỡ lỗi:** Sau khi xác định được phần code gây ra lỗi, bạn cần bỏ ghi chú lại phần code đó để chương trình có thể hoạt động bình thường. Quá trình gỡ lỗi thường bao gồm nhiều lần thêm, xóa và ghi chú/bỏ ghi chú code. Nếu bạn quên bỏ ghi chú một đoạn code nào đó, chương trình có thể bị lỗi hoặc hoạt động không mong đợi.
>- **Sử dụng hệ thống kiểm soát phiên bản:** Việc sử dụng hệ thống kiểm soát phiên bản (version control system) như ***Git*** sẽ giúp bạn theo dõi những thay đổi của code theo thời gian. Nhờ đó, bạn có thể dễ dàng quay lại phiên bản code hoạt động trước đó nếu việc bình luận code gây ra lỗi hoặc tạo ra các vấn đề khác. Hệ thống kiểm soát phiên bản cũng giúp bạn phân biệt các thay đổi liên quan đến gỡ lỗi với các thay đổi tính năng của chương trình.

>**Mẹo**<br>
>**Sử dụng thư viện debug tùy chọn:** Một cách tiếp cận khác để thêm các lệnh gỡ lỗi (debug statements) vào code là sử dụng thư viện của bên thứ ba. Các thư viện này cho phép bạn đưa các lệnh gỡ lỗi vào code nhưng sẽ loại bỏ chúng khi biên dịch ở chế độ phát hành (release mode). Điều này giúp bạn giữ code gọn gàng và tránh ảnh hưởng đến hiệu suất của chương trình khi nó đã hoạt động ổn định. `dbg` là một thư viện header-only tiêu biểu có chức năng này (thông qua macro tiền xử lý `DBG_MACRO_DISABLE`)
>
>Chúng ta sẽ thảo luận về các thư viện chỉ có tiêu đề trong bài 5.7 -- Các hàm và biến nội tuyến.

### **Chiến thuật gỡ lỗi #2: Kiểm tra luồng thực thi code**

Trong các chương trình phức tạp, một vấn đề thường gặp là việc một hàm được gọi quá nhiều lần, quá ít lần (hoặc thậm chí không được gọi).

Để kiểm tra xem các hàm có được gọi đúng cách hay không, bạn có thể đặt các lệnh in tên của hàm vào đầu mỗi hàm. Khi chương trình chạy, bạn sẽ theo dõi được thứ tự các hàm được gọi và xác định xem hàm nào không được gọi hoặc được gọi không đúng số lần.

>**Mẹo**<br>
>Khi in thông tin để gỡ lỗi, hãy sử dụng `std::cerr` thay vì `std::cout`. Có một lý do cho việc này: `std::cout` có thể được lưu trữ đệm (*buffere*), nghĩa là có thể có một khoảng dừng giữa lúc bạn yêu cầu `std::cout` xuất ra thông tin và khi nó thực sự xuất ra. Nếu bạn xuất thông tin bằng `std::cout` và sau đó chương trình của bạn bị lỗi ngay lập tức, `std::cout` có thể vẫn chưa xuất ra thông tin đó. Điều này có thể khiến bạn hiểu sai về vị trí của sự cố. Mặt khác, `std::cerr` không được lưu trữ đệm, nghĩa là bất kỳ thứ gì bạn gửi đến nó sẽ được xuất ra ngay lập tức. Điều này giúp đảm bảo tất cả đầu ra gỡ lỗi xuất hiện càng sớm càng tốt (mặc dù nó có thể ảnh hưởng một chút đến hiệu suất, nhưng hiệu suất thường không phải là vấn đề quan trọng khi gỡ lỗi).
>
>Sử dụng `std::cerr` cũng giúp phân biệt rõ ràng rằng thông tin được xuất ra là dành cho trường hợp lỗi chứ không phải trường hợp bình thường.
>
>Chúng ta sẽ thảo luận thêm về thời điểm sử dụng `std::cout` và `std::cerr` trong bài 9.4 -- Phát hiện và xử lý lỗi.

**Ví dụ:**

Xét chương trình đơn giản sau không hoạt động chính xác:
>```
>#include <iostream>
>
>int getValue()
>{
>    return 4;
>}
>
>int main()
>{
>    std::cout << getValue << '\n';
>
>    return 0;
>}
>```

Bạn có thể cần tắt "Treat warnings as errors" (Xử lý cảnh báo như lỗi) để biên dịch chương trình trên.

Mặc dù chúng ta mong đợi chương trình này sẽ in giá trị `4`, nhưng trên thực tế nó lại in giá trị 
>`1`.

Trên **Visual Studio** (và có thể một số trình biên dịch khác), nó có thể in ra thông tin sau:
>`00101424`

>**Nội dung liên quan**<br>
>Chúng ta sẽ thảo luận tại sao một số trình biên dịch in số `1` và địa chỉ (và phải làm gì nếu trình biên dịch của bạn in số `1` nhưng bạn muốn nó in địa chỉ) trong bài 20.1 -- Con trỏ hàm.

**Thêm lệnh gỡ lỗi:**

Chúng ta hãy thêm một số lệnh gỡ lỗi vào các hàm này:
>```
>#include <iostream>
>
>int getValue()
>{
>std::cerr << "getValue() called\n";
>    return 4;
>}
>
>int main()
>{
>std::cerr << "main() called\n";
>    std::cout << getValue << '\n';
>
>    return 0;
>}
>```

>**Mẹo**<br>
Khi thêm các câu lệnh gỡ lỗi tạm thời, việc không thụt lề chúng có thể hữu ích. Điều này làm cho chúng dễ dàng được tìm thấy để loại bỏ sau này. Nếu bạn đang sử dụng `clang-format` để định dạng mã của mình, nó sẽ cố gắng tự động thụt lề những dòng này. Bạn có thể chặn định dạng tự động như thế này:
>>```
>>// clang-format off
>>std::cerr << "main() called\n";
>>// clang-format on
>>```

Bây giờ khi các hàm này được thực thi, chúng sẽ xuất ra tên của chúng, cho biết chúng đã được gọi:
>```
>main() called
>1
>```

Bây giờ chúng ta có thể thấy rằng hàm `getValue` không bao giờ được gọi. Phải có vấn đề gì đó với dòng code gọi hàm. Hãy xem xét kỹ hơn dòng code đó:
>```
>std::cout << getValue << '\n';
>```

Ồ, quên mất dấu ngoặc đơn trong lệnh gọi hàm. Nó phải là:
>```
>#include <iostream>
>
>int getValue()
>{
>std::cerr << "getValue() called\n";
>    return 4;
>}
>
>int main()
>{
>std::cerr << "main() called\n";
>    std::cout << getValue() << '\n'; // thêm dấu ngoặc đơn ở đây
>
>    return 0;
>}
>```

Bây giờ chương trình sẽ tạo ra đầu ra chính xác:
>```
>main() called
>getValue() called
>4
>```

Và chúng ta có thể xóa các lệnh gỡ lỗi tạm thời.



### **Chiến thuật gỡ lỗi #3: In giá trị biến**

Một số lỗi trong chương trình có thể liên quan đến việc tính toán hoặc truyền sai giá trị biến.

Để đảm bảo các biến (bao gồm cả tham số) hoặc biểu thức có giá trị chính xác, chúng ta có thể in giá trị của chúng ra màn hình.

**Ví dụ:**

Xét chương trình sau đây được thiết kế để cộng hai số nhưng lại không hoạt động chính xác:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>    return x + y;
>}
>
>void printResult(int z)
>{
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>    int x{ getUserInput() };
>    int y{ getUserInput() };
>
>    std::cout << x << " + " << y << '\n';
>
>    int z{ add(x, 5) };
>    printResult(z);
>
>    return 0;
>}
>```

Kết quả chạy của chương trình này:
>```
>Enter a number: 4
>Enter a number: 3
>4 + 3
>The answer is: 9
>```



Kết quả không chính xác. Bạn có phát hiện ra lỗi không? Ngay cả trong chương trình ngắn này, việc xác định lỗi cũng có thể khó khăn. Hãy thêm một số lệnh gỡ lỗi để kiểm tra giá trị của các biến:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>    return x + y;
>}
>
>void printResult(int z)
>{
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>    int x{ getUserInput() };
>std::cerr << "main::x = " << x << '\n';
>    int y{ getUserInput() };
>std::cerr << "main::y = " << y << '\n';
>
>    std::cout << x << " + " << y << '\n';
>
>    int z{ add(x, 5) };
>std::cerr << "main::z = " << z << '\n';
>    printResult(z);
>
>	return 0;
>}
>```

Kết quả chạy với lệnh gỡ lỗi:
>```
>Enter a number: 4
>main::x = 4
>Enter a number: 3
>main::y = 3
>4 + 3
>main::z = 9
>The answer is: 9
>```

Các biến `x` và `y` đang nhận đúng giá trị, nhưng biến `z` thì không. Vấn đề có thể nằm giữa hai điểm đó, khiến hàm `add` trở thành nghi vấn chính.

**Sửa đổi hàm `add`:**
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>std::cerr << "add() called (x=" << x <<", y=" << y << ")\n";
>    return x + y;
>}
>
>void printResult(int z)
>{
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>    int x{ getUserInput() };
>std::cerr << "main::x = " << x << '\n';
>    int y{ getUserInput() };
>std::cerr << "main::y = 3" << '\n';
>
>    std::cout << x << " + " << y << '\n';
>
>    int z{ add(x, 5) };
>std::cerr << "main::z = " << z << '\n';
>    printResult(z);
>
>    return 0;
>}
>```

Bây giờ chúng ta sẽ nhận được kết quả:
>```
>Enter a number: 4
>main::x = 4
>Enter a number: 3
>main::y = 3
>add() called (x=4, y=5)
>main::z = 9
>The answer is: 9
>```

Biến `y` có giá trị `3`, nhưng bằng cách nào đó hàm `add` của chúng ta lại nhận được giá trị `5` cho tham số `y`. Chắc hẳn chúng ta đã đưa ra lập luận sai lầm.  Chắc chắn chúng ta đã truyền nhầm đối số.
>`int z{ add(x, 5) };`

Đúng vậy. Chúng ta đã truyền `5` thay vì truyền giá trị của biến y làm đối số. Đây là lỗi dễ sửa và sau khi sửa xong, chúng ta có thể xóa các lệnh gỡ lỗi đi.

Xóa lệnh gỡ lỗi và sửa lỗi:
>`int z{ add(x, y) };`

Bây giờ chương trình sẽ hoạt động chính xác và bạn có thể xóa các lệnh gỡ lỗi `std::cerr`.

In giá trị biến là một chiến thuật gỡ lỗi hữu ích giúp bạn theo dõi giá trị của biến tại các điểm khác nhau trong chương trình. Bằng cách kiểm tra giá trị của biến, bạn có thể xác định chính xác vị trí xảy ra lỗi và sửa chữa nó một cách hiệu quả.

### **Một ví dụ khác**

Chương trình này rất giống với chương trình trước đó, nhưng cũng không hoạt động như mong đợi:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>    return x + y;
>}
>
>void printResult(int z)
>{
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return --x;
>}
>
>int main()
>{
>    int x{ getUserInput() };
>    int y{ getUserInput() };
>
>    int z { add(x, y) };
>    printResult(z);
>
>    return 0;
>}
>```

Chạy đoạn code này và nhận được kết quả:
>```
>Enter a number: 4
>Enter a number: 3
>The answer is: 5
>```

Ồ, có gì đó không ổn. Nhưng ở đâu?

**Thêm lệnh gỡ lỗi:**

Chúng ta hãy thêm một số lệnh gỡ lỗi vào code:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>std::cerr << "add() called (x=" << x << ", y=" << y << ")\n";
>    return x + y;
>}
>
>void printResult(int z)
>{
>std::cerr << "printResult() called (z=" << z << ")\n";
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>std::cerr << "getUserInput() called\n";
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return --x;
>}
>
>int main()
>{
>std::cerr << "main() called\n";
>    int x{ getUserInput() };
>std::cerr << "main::x = " << x << '\n';
>    int y{ getUserInput() };
>std::cerr << "main::y = " << y << '\n';
>
>    int z{ add(x, y) };
>    std::cerr << "main::z = " << z << '\n';
>    printResult(z);
>
>    return 0;
>}
>```

Chạy lại chương trình với cùng dữ liệu đầu vào:
>```
>main() called
>getUserInput() called
>Enter a number: 4
>main::x = 3
>getUserInput() called
>Enter a number: 3
>main::y = 2
>add() called (x=3, y=2)
>main::z = 5
>printResult() called (z=5)
>The answer is: 5
>```

Bây giờ chúng ta có thể thấy ngay vấn đề: Người dùng nhập giá trị `4`, nhưng biến `x` của hàm `main` lại nhận giá trị `3`. Phải có gì đó không ổn giữa chỗ người dùng nhập dữ liệu và nơi gán giá trị đó cho biến `x` của hàm `main`.

Để đảm bảo chương trình nhận được giá trị chính xác từ người dùng, chúng ta hãy thêm một số lệnh gỡ lỗi vào hàm `getUserInput`:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>std::cerr << "add() called (x=" << x << ", y=" << y << ")\n";
>    return x + y;
>}
>
>void printResult(int z)
>{
>std::cerr << "printResult() called (z=" << z << ")\n";
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>std::cerr << "getUserInput() called\n";
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>std::cerr << "getUserInput::x = " << x << '\n'; // added this additional line of debugging
>    return --x;
>    }
>
>int main()
>{
>std::cerr << "main() called\n";
>    int x{ getUserInput() };
>std::cerr << "main::x = " << x << '\n';
>    int y{ getUserInput() };
>std::cerr << "main::y = " << y << '\n';
>
>    int z{ add(x, y) };
>std::cerr << "main::z = " << z << '\n';
>    printResult(z);
>
>    return 0;
>}
>```


Bây giờ hãy chạy lại chương trình với cùng thông tin đầu vào:

>```
>main() called
>getUserInput() called
>Enter a number: 4
>getUserInput::x = 4
>main::x = 3
>getUserInput() called
>Enter a number: 3
>getUserInput::x = 3
>main::y = 2
>add() called (x=3, y=2)
>main::z = 5
>printResult() called (z=5)
>The answer is: 5
>```

Với dòng gỡ lỗi bổ sung này, chúng ta có thể thấy giá trị người dùng nhập được lưu chính xác vào biến `x` của hàm `getUserInput`. Nhưng bằng cách nào đó biến `x` của hàm `main` lại nhận giá trị không mong đợi. Vấn đề phải nằm giữa hai điểm đó. Thủ phạm duy nhất còn lại là giá trị trả về từ hàm `getUserInput`. Hãy xem kỹ dòng code đó:
>`return --x;`

**Kiểm tra dòng code gây ra lỗi:**

Hmmm, đây là điều kỳ lạ. Ký hiệu `--` trước `x` là gì? Trong các bài hướng dẫn này, chúng ta chưa đề cập đến nó, vì vậy đừng lo lắng nếu bạn không biết nó có nghĩa là gì. Nhưng ngay cả khi không biết ý nghĩa của nó, thông qua các nỗ lực gỡ lỗi của bạn, bạn có thể tin chắc rằng dòng code cụ thể này có vấn đề - và do đó, ký hiệu `--` này có khả năng gây ra sự cố.

**Sửa lỗi:**

Vì mục đích của chúng ta là hàm `getUserInput` chỉ trả về giá trị của `x`, hãy xóa bỏ `--` và xem điều gì xảy ra:
>```
>#include <iostream>
>
>int add(int x, int y)
>{
>std::cerr << "add() called (x=" << x << ", y=" << y << ")\n";
>    return x + y;
>}
>
>void printResult(int z)
>{
>std::cerr << "printResult() called (z=" << z << ")\n";
>    std::cout << "The answer is: " << z << '\n';
>}
>
>int getUserInput()
>{
>std::cerr << "getUserInput() called\n";
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>std::cerr << "getUserInput::x = " << x << '\n';
>    return x; // Xóa bỏ -- trước x
>}
>
>int main()
>{
>std::cerr << "main() called\n";
>    int x{ getUserInput() };
>std::cerr << "main::x = " << x << '\n';
>    int y{ getUserInput() };
>std::cerr << "main::y = " << y << '\n';
>
>    int z{ add(x, y) };
>std::cerr << "main::z = " << z << '\n';
>    printResult(z);
>
>    return 0;
>}
>```

**Chạy chương trình đã sửa:**

Bây giờ đầu ra là:
>```
>main() called
>getUserInput() called
>Enter a number: 4
>getUserInput::x = 4
>main::x = 4
>getUserInput() called
>Enter a number: 3
>getUserInput::x = 3
>main::y = 3
>add() called (x=4, y=3)
>main::z = 7
>printResult() called (z=7)
>The answer is: 7
>```

Chương trình hiện hoạt động chính xác. Ngay cả khi không hiểu `--` làm gì, chúng ta vẫn có thể xác định dòng mã cụ thể gây ra sự cố và sau đó khắc phục sự cố.

### **Những hạn chế của việc sử dụng lệnh in để gỡ lỗi**

Mặc dù việc thêm lệnh in vào chương trình để chẩn đoán lỗi là một kỹ thuật phổ biến và hiệu quả (đặc biệt khi không có trình gỡ lỗi), nó không thực sự tốt vì một số lý do sau:
1. **Lệnh in làm lộn xộn mã code:**<br>
Lệnh in khiến mã code trở nên rối ren và khó đọc, đặc biệt là khi bạn có nhiều lệnh in.
2. **Lệnh in làm lộn xộn đầu ra chương trình:**<br>
Đầu ra từ chương trình có thể bị ngập lụt bởi các thông báo gỡ lỗi, khiến bạn khó tìm thấy thông tin thực sự cần thiết.
3. **Tốn thời gian và dễ mắc lỗi khi chỉnh sửa:**<br>
Việc thêm và xóa lệnh in đòi hỏi phải thay đổi mã code. Điều này có thể tốn thời gian và dễ mắc lỗi, tiềm ẩn nguy cơ phát sinh lỗi mới.
4. **Lệnh in không thể tái sử dụng:**
Lệnh in thường chỉ dành cho một phiên gỡ lỗi cụ thể. Sau khi bạn đã sửa lỗi, bạn cần xóa chúng, khiến chúng không thể tái sử dụng cho các nhu cầu gỡ lỗi trong tương lai.

**Có cách tốt hơn!**

Trong các bài học sau, bạn sẽ khám phá các kỹ thuật gỡ lỗi tiên tiến hơn có thể giải quyết những hạn chế này. Các kỹ thuật này có thể bao gồm sử dụng trình gỡ lỗi, một công cụ chuyên dụng cho phép bạn từng bước thực hiện mã code và kiểm tra giá trị của các biến tại bất kỳ điểm nào. Bạn cũng có thể tìm hiểu về các khung gỡ lỗi có thể được sử dụng để ghi lại các sự kiện quan trọng trong quá trình thực thi chương trình, giúp bạn dễ dàng theo dõi các vấn đề hơn.
