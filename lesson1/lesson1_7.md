## <u>**Bài 1.7: Từ khóa và cách đặt tên định danh**</u>

C++ dành riêng một bộ gồm 92 từ (tính đến C++23) được định nghĩa sẵn. Những từ này được gọi là từ khóa (hoặc từ dành riêng), mỗi từ khóa đều có một ý nghĩa đặc biệt trong ngôn ngữ C++.

| `alignas`<br>`alignof`<br>`and`<br>`and_eq`<br>`asm`<br>`auto`<br>`bitand`<br>`bitor`<br>`bool`<br>`break`<br>`case`<br>`catch`<br>`char`<br>`char8_t` (since `C++20`)<br>`char16_t`<br>`char32_t`<br>`class`<br>`compl`<br>`concept` (since `C++20`)<br>`const`<br>`consteval` (since `C++20`)<br>`constexpr`<br>`constinit` (since `C++20`) | `const_cast`<br>`continue`<br>`co_await` (since `C++20`)<br>`co_return` (since `C++20`)<br>`co_yield` (since `C++20`)<br>`decltype`<br>`default`<br>`delete`<br>`do`<br>`double`<br>`dynamic_cast`<br>`else`<br>`enum`<br>`explicit`<br>`export`<br>`extern`<br>`false`<br>`float`<br>`for`<br>`friend`<br>`goto`<br>`if`<br>`inline` | `int`<br>`long`<br>`mutable`<br>`namespace`<br>`new`<br>`noexcept`<br>`not`<br>`not_eq`<br>`nullptr`<br>`operator`<br>`or`<br>`or_eq`<br>`private`<br>`protected`<br>`public`<br>`register`<br>`reinterpret_cast`<br>`requires` (since `C++20`)<br>`return`<br>`short`<br>`signed`<br>`sizeof`<br>`static` | `static_assert`<br>`static_cast`<br>`struct`<br>`switch`<br>`template`<br>`this`<br>`thread_local`<br>`throw`<br>`true`<br>`try`<br>`typedef`<br>`typeid`<br>`typename`<br>`union`<br>`unsigned`<br>`using`<br>`virtual`<br>`void`<br>`volatile`<br>`wchar_t`<br>`while`<br>`xor`<br>`xor_eq` |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

>Lưu ý: Các từ khóa được đánh dấu (C++20) được thêm vào trong C++20. Nếu trình biên dịch của bạn không hỗ trợ C++20 (hoặc có chức năng C++20 nhưng mặc định bị tắt), các từ khóa này có thể không hoạt động.

C++ cũng định nghĩa các định danh đặc biệt: `override`, `final`, `import` và `module`. Chúng có ý nghĩa cụ thể khi được sử dụng trong một số ngữ cảnh nhất định nhưng không bị dành riêng trong các trường hợp khác.

Bạn có thể đã gặp một số từ khóa này, bao gồm `int` và `return`. Cùng với một tập hợp các toán tử, các từ khóa và định danh đặc biệt này định nghĩa toàn bộ ngôn ngữ **C++** (ngoại trừ các lệnh tiền xử lý). Bởi vì từ khóa và định danh đặc biệt có ý nghĩa đặc biệt, IDE của bạn có thể thay đổi màu sắc của các từ này để làm chúng nổi bật so với các định danh khác.

Khi hoàn thành loạt bài hướng dẫn này, bạn sẽ hiểu được ý nghĩa của hầu hết các từ khóa này!

### **Quy tắc đặt tên cho định danh (Identifier naming rules)**

Như một lời nhắc nhở, tên của một biến (hoặc hàm, kiểu dữ liệu, hoặc loại đối tượng khác) được gọi là định danh (**identifier**). C++ cung cấp cho bạn nhiều sự linh hoạt để đặt tên cho các định danh theo ý muốn. Tuy nhiên, có một vài quy tắc cần tuân theo khi đặt tên cho định danh:

**1. Không trùng với từ khóa:** Từ khóa là các từ được C++ dành riêng để sử dụng cho các mục đích nội bộ của ngôn ngữ và không thể được dùng làm tên cho các định danh.\
**2. Ký tự hợp lệ:** Tên định danh chỉ được bao gồm các ký tự sau:\
    - Chữ cái (in hoa hoặc thường)\
    - Số\
    - Ký tự gạch dưới (_) \
    **Lưu ý:** Không được chứa các ký hiệu khác (ngoại trừ dấu gạch dưới) hoặc khoảng trắng (dấu cách hoặc tab).\
**3. Bắt đầu bằng chữ cái hoặc dấu gạch dưới:** Tên định danh phải bắt đầu bằng một chữ cái (in hoa hoặc thường) hoặc dấu gạch dưới. Không được bắt đầu bằng số.\
**4. Phân biệt chữ hoa/thường:** **C++** phân biệt chữ hoa và chữ thường, do đó `nvalue` khác với `nValue` và khác với `NVALUE`.


### **Quy tắc ngón tay cái về cách đặt tên định danh:**

Bây giờ bạn đã biết có thể đặt tên cho biến như thế nào, chúng ta hãy thảo luận về **nên** đặt tên cho biến (hoặc hàm) như thế nào.

#### <u>*Quy tắc khuyên dùng:*</u>

1. **Chữ cái thường ở đầu:**
- Theo quy ước trong C++, tên biến nên bắt đầu bằng một chữ cái thường. Nếu tên biến là một từ đơn hoặc viết tắt, toàn bộ tên nên được viết thường.

>`int giaTri; // Theo quy ước (conventional)`
>
>`int GiaTri; // Không theo quy ước (nên bắt đầu bằng chữ thường)`\
>`int GIA_TRI; // Không theo quy ước (nên bắt đầu bằng chữ thường và viết toàn bộ chữ thường)`\
>`int GiATrI; // Không theo quy ước (bạn nên gặp bác sĩ tâm lý) ;)`

2. **Tên hàm:**
- Tên hàm thường cũng được bắt đầu bằng một chữ cái thường (mặc dù có một số ý kiến ​​khác nhau về điểm này). Chúng ta sẽ tuân theo quy ước này, vì hàm chính `main` (mà tất cả các chương trình phải có) bắt đầu bằng chữ thường, giống như tất cả các hàm trong thư viện chuẩn C++.
3. **Chữ cái hoa cho kiểu dữ liệu:**
- Tên định danh bắt đầu bằng chữ cái in hoa thường được sử dụng cho các kiểu dữ liệu do người dùng tự định nghĩa (chẳng hạn như cấu trúc (**struct**), lớp (**class**) và liệt kê (**enum**), tất cả sẽ được đề cập sau).
4. **Cụm từ:**
- Nếu tên biến hoặc hàm là nhiều từ, thì có hai quy ước phổ biến: phân cách các từ bằng dấu gạch dưới (đôi khi được gọi là `snake_case` (quy tắc con rắn)) hoặc viết hoa các chữ cái đầu (đôi khi được gọi là `camelCase` (quy tắc lạc đà), vì các chữ cái in hoa nhô lên giống như bướu trên lưng lạc đà).
- Ví dụ:
>`int ten_bien_cua_toi;  // Theo quy ước (phân cách bằng dấu gạch dưới/snake_case)`\
>`int ten_ham_cua_toi(); // Theo quy ước (phân cách bằng dấu gạch dưới/snake_case)`
>
>`int TenBienCuaToi;     // Theo quy ước (viết hoa các chữ cái đầu/camelCase)`\
>`int TenHamCuaToi();   // Theo quy ước (viết hoa các chữ cái đầu/camelCase)`
>
>`int ten bien cua toi;  // Không hợp lệ (khoảng trắng không được phép)`\
>`int ten ham cua toi(); // Không hợp lệ (khoảng trắng không được phép)`
>
>`int TenBienCuaToi;     // Không theo quy ước (nên bắt đầu bằng chữ thường)`\
>`int TenHamCuaToi();   // Không theo quy ước (nên bắt đầu bằng chữ thường)`

Trong hướng dẫn này, chúng tôi thường sử dụng cách viết hoa các chữ cái đầu vì nó dễ đọc hơn (dễ dàng nhầm lẫn dấu gạch dưới với khoảng trắng trong các khối mã dày đặc). Nhưng thông thường, cả hai cách đều được sử dụng - thư viện chuẩn C++ sử dụng phương pháp dấu gạch dưới cho cả biến và hàm. Đôi khi bạn sẽ thấy sự kết hợp của cả hai: quy tắc con rắn được sử dụng cho biến và quy tắc lạc đà được sử dụng cho hàm.

Điều đáng lưu ý là nếu bạn đang làm việc với mã của người khác, thì nhìn chung nên tuân theo phong cách của mã bạn đang làm việc hơn là tuân theo quy ước đặt tên một cách cứng nhắc như đã nêu ở trên.

>**Thực tiễn:**
> - Khi làm việc trong một chương trình hiện có, hãy sử dụng các quy ước của chương trình đó (ngay cả khi chúng không tuân theo các quy tắc hiện đại).
> - Sử dụng các quy tắc được khuyên dùng ở trên khi bạn đang viết chương trình mới.


#### <u>*Quy tắc nên tránh:*</u>

5. **Tránh dấu gạch dưới ở đầu:**
- Bạn nên tránh đặt tên định danh bắt đầu bằng dấu gạch dưới, vì những tên này thường được dành riêng cho hệ điều hành, thư viện hoặc trình biên dịch sử dụng.
6. **Tên không rõ nghĩa:**
- Thứ ba, tên định danh của bạn nên thể hiện rõ ràng ý nghĩa của giá trị mà chúng lưu trữ (đặc biệt nếu đơn vị giá trị biến không rõ ràng). Tên định danh nên được đặt tên theo cách giúp người không biết gì về mã của bạn có thể hiểu được nó nhanh nhất có thể. Ba tháng sau, khi bạn xem lại chương trình của mình, bạn sẽ quên cách hoạt động của nó và sẽ tự cảm ơn bản thân vì đã chọn những tên biến có ý nghĩa.
- Tuy nhiên, đặt tên quá phức tạp cho một biến đơn giản sẽ cản trở việc hiểu tổng thể về những gì chương trình đang làm, gần giống như việc đặt tên không chính xác cho một định danh được sử dụng rộng rãi. Do đó, một nguyên tắc hay là làm cho độ dài của tên định danh tương ứng với mức độ phổ biến của nó. Một định danh có công dụng đơn giản có thể có tên ngắn (ví dụ: `i`). Một định danh được sử dụng rộng rãi hơn (ví dụ: hàm được gọi từ nhiều vị trí khác nhau trong chương trình) nên có tên dài hơn và mô tả nhiều hơn (ví dụ: thay vì `open`, hãy thử `openFileOnDisk`).



>`int dem_k; //không tốt, k nghĩa là gì sau dem`\
>`int soLuongKhachHang; //Tốt, thể hiện số lượng gì đang được đếm`\
>`int i; //Tùy trường hợp có thể tốt hoặc tệ`\
>`int chiSo; //Tùy trường hợp, nếu ta biết đang làm gì`\
>`int tongDiem; //Tùy trường hợp, tốt nếu chỉ có 1 tổng được tính, nếu không thì khá mơ hồ`\
>`int _dem; //Không tốt, tên biến không nên bắt đầu bằng dấu gạch dưới`\
>`int dem; //Tùy trường hợp, nếu chúng ta biết đang đếm cái gì`\
>`int data;	//Không tốt, loại dữ liệu gì?`\
>`int time;	//Không tốt, biến đếm thời gian theo đơn vị gì? Giờ, hay phút, giây?`\
>`int soPhutDaChay; //Tốt, mô tả rõ ràng`\
>`int giaTri1, giaTri2; //Tùy trường hợp, khó phân biệt giữa 2 biến`\
>`int soTao; //Tốt, mô tả rõ ràng`\
>`int soQuaiGietDuoc; //Tốt`\
>`int x, y; //Tùy trường hợp, có thể tốt hoặc không`

7. **Tránh viết tắt:**
- Trong mọi trường hợp, hãy tránh sử dụng các viết tắt (trừ khi chúng phổ biến/không gây nhầm lẫn). Mặc dù chúng giúp giảm thời gian bạn cần để viết code, nhưng chúng lại khiến code của bạn khó đọc hơn. Code được đọc nhiều hơn so với việc viết, thời gian bạn tiết kiệm khi viết code sẽ là thời gian mà mọi người đọc nó, bao gồm cả bạn trong tương lai, lãng phí khi đọc. Nếu bạn muốn viết code nhanh hơn, hãy sử dụng tính năng tự động hoàn thành (auto completion) của trình soạn thảo.
8. **Lười comment:**
- Đối với việc khai báo biến, việc sử dụng comment để mô tả biến sẽ được sử dụng để làm gì hoặc giải thích bất kỳ điều gì khác có thể không rõ ràng là rất hữu ích. Ví dụ: giả sử chúng tôi đã khai báo một biến có tên `soKyTu` được cho là lưu trữ số ký tự trong một đoạn văn bản. Đoạn văn bản **"Hello World!"** có 10, 11 hay 12 ký tự? Nó phụ thuộc vào việc chúng ta có bao gồm khoảng trắng hoặc dấu câu hay không. Thay vì đặt tên biến là `soKyTuBaoGomKhoangTrangVaDauCau`, thì một comment được đặt đúng chỗ trên hoặc bên trên dòng khai báo sẽ giúp người dùng hiểu được:
>`// Số lượng ký tự trong một đoạn văn bản, bao gồm cả khoảng trắng và dấu câu`\
>`int soKyTu;`
