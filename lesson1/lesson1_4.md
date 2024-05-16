## **Bài 1.4: <u>Gán và khởi tạo giá trị cho biến</u>**


### **Phép gán**

- Sau khi một biến đã được khai báo, bạn có thể gán cho nó một giá trị (trong một câu lệnh riêng) bằng toán tử `=`. Quá trình này được gọi là phép gán và toán tử `=` được gọi là toán tử gán.
>```
>int width; // define an integer variable named width
>width = 5; // assignment of value 5 into variable width
>// variable width now has value 5
>```
- Theo mặc định, phép gán sẽ sao chép giá trị ở vế phải của toán tử `=` sang biến ở vế trái của toán tử. Đây được gọi là gán sao chép (copy assignment).
- Ví dụ gán giá trị nhiều lần:
>```
>#include <iostream>
>
>int main()
>{
>	int width;
>	width = 5; // copy assignment of value 5 into variable width
>
>	std::cout << width; // prints 5
>
>	width = 7; // change value stored in variable width to 7
>
>	std::cout << width; // prints 7
>
>	return 0;
>}
>```
- Đoạn code này in ra:
> `57`
- Khi chúng ta gán giá trị `7` cho biến `width`, giá trị `5` trước đó sẽ bị ghi đè. Biến thông thường chỉ có thể chứa một giá trị tại một thời điểm.


### **Khởi tạo giá trị cho biến (initialization)** 

- Gán giá trị cho biến yêu cầu ít nhất hai câu lệnh: một để khai báo biến và một để gán giá trị.
- Hai bước này có thể được kết hợp. Khi một đối tượng được định nghĩa, bạn có thể tùy chọn cung cấp cho nó một giá trị ban đầu. Quá trình chỉ định giá trị ban đầu cho một đối tượng được gọi là khởi tạo (**initialization**), và cú pháp được sử dụng để khởi tạo một đối tượng được gọi là trình khởi tạo (**initializer**).
> - Ví dụ:
>```
>int width { 5 }; // Định nghĩa biến width và khởi tạo với giá trị ban đầu là 5
>
>// Biến width bây giờ có giá trị là 5
>```


### **Các dạng khởi tạo khác nhau**

- Khởi tạo trong C++ phức tạp hơn so với tưởng tượng, vì vậy chúng ta sẽ chỉ trình bày một cách đơn giản ở đây.
- Có 6 cách cơ bản để khởi tạo biến trong C++:
    >`int a; // Không có trình khởi tạo (khởi tạo mặc định)`\
    >`int b = 5; // Giá trị ban đầu sau dấu bằng (khởi tạo sao chép)`\
    >`int c( 6 ); // Giá trị ban đầu trong dấu ngoặc đơn (khởi tạo trực tiếp)`\
    >`// Phương thức khởi tạo danh sách (C++11) (ưu tiên)`\
    >`int d { 7 }; // Giá trị ban đầu trong ngoặc nhọn (khởi tạo danh sách trực tiếp)`\
    >`int e = { 8 }; // Giá trị ban đầu trong ngoặc nhọn sau dấu bằng (khởi tạo danh sách sao chép)`\
    >`int f {}; // Trình khởi tạo là ngoặc nhọn trống (khởi tạo giá trị)`
    


#### *<u>Khởi tạo mặc định (Default initialization)</u>.*

Khi không cung cấp trình khởi tạo (chẳng hạn như đối với biến `a` ở trên), thì đây được gọi là **khởi tạo mặc định**. Trong hầu hết các trường hợp, khởi tạo mặc định không thực hiện bất kỳ khởi tạo nào và để lại biến với giá trị không xác định.

#### *<u>Khởi tạo sao chép (Copy initialization)</u>.*

Khi cung cấp giá trị ban đầu sau dấu bằng, thì đây được gọi là **khởi tạo sao chép**. Hình thức khởi tạo này được thừa hưởng từ **C**.
>`int width = 5; // Khởi tạo sao chép giá trị 5 vào biến width`

Giống như gán sao chép, nó sao chép giá trị bên phải dấu bằng vào biến được tạo bên trái. Trong đoạn mã trên, biến `width` sẽ được khởi tạo với giá trị `5`.

Khởi tạo sao chép không còn được ưa chuộng trong C++ hiện đại do kém hiệu quả hơn các hình thức khởi tạo khác đối với một số kiểu dữ liệu phức tạp. Tuy nhiên, `C++17` đã khắc phục hầu hết các vấn đề này và khởi tạo sao chép hiện đang tìm lại chỗ đứng.

>**Đối với người đọc nâng cao**\
>Khởi tạo sao chép cũng được sử dụng bất cứ khi nào các giá trị được sao chép hoặc chuyển đổi ngầm, chẳng hạn như khi truyền đối số cho một hàm theo giá trị, trả về từ một hàm theo giá trị hoặc bắt các ngoại lệ theo giá trị.

#### *<u>Khởi tạo trực tiếp (Direct initialization)</u>.*

Khi cung cấp giá trị ban đầu bên trong dấu ngoặc đơn, thì đây được gọi là khởi tạo trực tiếp.

>`int width( 5 ); // Khởi tạo trực tiếp giá trị 5 vào biến width`

Khởi tạo trực tiếp ban đầu được giới thiệu để cho phép khởi tạo các đối tượng phức tạp (các đối tượng có kiểu lớp, chúng tôi sẽ đề cập trong một chương học sau) hiệu quả hơn. Giống như khởi tạo sao chép, khởi tạo trực tiếp không còn được ưa chuộng trong C++ hiện đại, chủ yếu là do nó bị thay thế bởi khởi tạo danh sách. Tuy nhiên, hiện tại chúng ta biết rằng khởi tạo danh sách có một vài điểm kỳ quặc, do đó khởi tạo trực tiếp lại được sử dụng trong một số trường hợp nhất định.

Khởi tạo trực tiếp cũng được sử dụng khi các giá trị được ép kiểu rõ ràng sang một kiểu khác.

Một trong những lý do khiến khởi tạo trực tiếp không còn được ưa chuộng là vì nó gây khó khăn trong việc phân biệt biến với hàm. Ví dụ:
>`int x();  // Khai báo trước hàm x`\
>`int x(0); // Định nghĩa biến x với giá trị khởi tạo là 0`


#### *<u>Khởi tạo danh sách (List initialization)</u>.*

Khởi tạo danh sách (List initialization) là cách thức hiện đại để khởi tạo các đối tượng trong C++. Nó còn được gọi là khởi tạo đồng nhất (uniform initialization) hoặc khởi tạo bằng ngoặc nhọn (brace initialization).

<u>Ba dạng khởi tạo danh sách:</u>

**1.** Khởi tạo danh sách trực tiếp (direct list initialization):
>`int width { 5 };    // Khởi tạo biến width với giá trị ban đầu là 5`

**2.** Khởi tạo danh sách sao chép (copy list initialization):
>`int height = { 6 }; // Gán giá trị 6 cho biến height`

**3.** Khởi tạo giá trị (value initialization):
>`int depth {};       // Khởi tạo biến depth với giá trị rỗng (sẽ được giải thích chi tiết sau)` 

Trước khi có khởi tạo danh sách:
- Trước đây, tùy thuộc vào kiểu dữ liệu, bạn cần sử dụng khởi tạo sao chép (copy initialization) hoặc khởi tạo trực tiếp (direct initialization). Khởi tạo danh sách được ra đời để cung cấp cú pháp khởi tạo thống nhất (do đó đôi khi được gọi là khởi tạo đồng nhất) hoạt động trong hầu hết các trường hợp.
- Ngoài ra, khởi tạo danh sách còn cho phép khởi tạo đối tượng với một danh sách các giá trị (do đó được gọi là khởi tạo danh sách). Ví dụ về cách khởi tạo này sẽ được giới thiệu trong bài học sau về các hàm tạo của `std::vector` và `std::list`.

<u>Lợi ích của khởi tạo danh sách:</u>
- **Ngăn chặn chuyển đổi hẹp (narrowing conversions)**: Khi sử dụng khởi tạo danh sách, việc gán các giá trị không phù hợp kiểu dữ liệu của biến sẽ gây ra lỗi. Điều này giúp tránh mất mát dữ liệu.
>`int width { 4.5 }; // Lỗi: số thập phân không thể gán cho biến nguyên`

    - Trong đoạn code trên, biến `width` kiểu `int` (chỉ lưu trữ số nguyên) nhưng chúng ta lại cố gắng gán cho nó một số thập phân (`4.5`).
    - **Khởi tạo sao chép** và **khởi tạo trực tiếp** sẽ loại bỏ phần thập phân, gán giá trị `4` cho biến `width`. Trình biên dịch của bạn có thể cảnh báo về việc mất mát dữ liệu này. Tuy nhiên, với khởi tạo danh sách, trình biên dịch bắt buộc phải báo lỗi trong trường hợp này.
- **Các phép chuyển đổi không gây mất mát dữ liệu vẫn được phép.**

<u>Tóm tắt:</u>

Khởi tạo danh sách thường được ưu tiên hơn các hình thức khởi tạo khác vì:

- Hoạt động trong hầu hết các trường hợp (tính nhất quán cao).
- Ngăn chặn chuyển đổi hẹp (tránh mất mát dữ liệu).
- Hỗ trợ khởi tạo với danh sách giá trị (sẽ được học sau).

<u>Khuyến nghị:</u>
- Trong khi học, nên ưu tiên sử dụng khởi tạo danh sách trực tiếp (hoặc khởi tạo giá trị) để khởi tạo biến.


#### *<u>Khởi tạo giá trị và khởi tạo bằng 0 (Value initialization and zero initialization)</u>.*

<u>Khởi tạo giá trị (Value initialization):</u>
- Khi bạn khởi tạo biến bằng ngoặc nhọn rỗng {}, quá trình khởi tạo giá trị (value initialization) diễn ra.
- Trong hầu hết các trường hợp, khởi tạo giá trị sẽ gán giá trị 0 cho biến (hoặc giá trị rỗng đối với kiểu dữ liệu phù hợp).
- Ví dụ:
>`int width {}; // Khởi tạo biến width với giá trị 0 (khởi tạo giá trị / khởi tạo bằng 0)`

<u>Câu hỏi:</u> *Nên dùng `{}` hay `{0}` để khởi tạo giá trị?*
- Sử dụng giá trị khởi tạo rõ ràng (`{0}`) nếu bạn thực sự sử dụng giá trị đó.
- Ví dụ:
>`int x {0};    // Khởi tạo rõ ràng biến x với giá trị 0`\
>`std::cout << x; // In ra giá trị 0`

<u>LỜI KHUYÊN:</u> Khởi tạo biến ngay khi tạo.
- Khởi tạo biến với giá trị mặc định (0, giá trị rỗng, ...) thường là lựa chọn tốt. Điều này giúp bạn tránh những vấn đề do biến chưa được khởi tạo gây ra.
- Sử dụng khởi tạo danh sách (list initialization) - Đây là cách thức hiện đại và an toàn để khởi tạo biến trong C++.


### **Khởi tạo nhiều biến trong C++**

<u>Định nghĩa nhiều biến cùng kiểu:</u>
- Trong bài trước, chúng ta đã biết có thể khai báo nhiều biến cùng kiểu trong một câu lệnh bằng cách phân cách các tên biến bằng dấu phẩy:
>`int a, b;`

- Tuy nhiên, theo khuyến cáo, bạn nên tránh sử dụng cách thức này. Tuy nhiên, vì bạn có thể gặp code cũ sử dụng cách này, nên chúng ta vẫn cần tìm hiểu thêm về nó.
- Khởi tạo nhiều biến trên cùng một dòng: Bạn có thể khởi tạo nhiều biến được khai báo trên cùng một dòng:
>```
>int a = 5, b = 6;          // Khởi tạo sao chép (copy initialization)
>int c( 7 ), d( 8 );        // Khởi tạo trực tiếp (direct initialization)
>int e { 9 }, f { 10 };     // Khởi tạo danh sách trực tiếp (direct brace initialization)
>int g = { 9 }, h = { 10 }; // Khởi tạo danh sách sao chép (copy brace initialization)
>int i {}, j {};            // Khởi tạo giá trị (value initialization)
>```

<u>Lỗi thường gặp:</u>
- Một lỗi thường gặp là lập trình viên cố gắng khởi tạo cả hai biến bằng một câu lệnh khởi tạo:
>`int a, b = 5; // Sai (biến a không được khởi tạo!`
- Cách viết chính xác:
>`int a = 5, b = 5; // Đúng`
- Trong câu lệnh sai ở trên, biến a sẽ không được khởi tạo. Trình biên dịch có thể hoặc không báo lỗi. Nếu không báo lỗi, điều này có thể khiến chương trình của bạn chạy không ổn định hoặc cho ra kết quả không mong đợi.
- **Cách nhớ để tránh lỗi:** Cách tốt nhất để nhớ đây là lỗi là xem xét trường hợp khởi tạo trực tiếp hoặc khởi tạo danh sách:
>`int a, b( 5 );  // Sai (bị hiểu nhầm là khởi tạo cho cả a và b)`\
>`int c, d{ 5 };  // Sai (bị hiểu nhầm là khởi tạo cho cả c và d)`
- Vì dấu ngoặc đơn hoặc ngoặc nhọn thường được đặt ngay cạnh tên biến, điều này khiến cho việc khởi tạo giá trị 5 chỉ dành cho biến b và d, không phải a hoặc c.





### **Cảnh báo biến được khởi tạo nhưng không sử dụng (Unused initialized variables warnings)**

- Trình biên dịch hiện đại thường sẽ cảnh báo nếu một biến được khởi tạo nhưng không được sử dụng (vì điều này hiếm khi cần thiết). Và nếu bật tùy chọn "xử lý cảnh báo như lỗi" (treat warnings as errors), các cảnh báo này sẽ được nâng cấp thành lỗi và khiến quá trình biên dịch thất bại.
- Xét ví dụ chương trình đơn giản sau:
>```
>int main()
>{
>    int x { 5 }; // Biến x được khai báo và khởi tạo
>
>    // Nhưng không được sử dụng ở bất kỳ đâu
>
>    return 0;
>}
>```
- Khi biên dịch chương trình này với trình biên dịch `g++`, lỗi sau sẽ được tạo:
>```
>prog.cc: In function 'int main()':
>prog.cc:3:9: error: unused variable 'x' [-Werror=unused-variable]
>```

Chương trình sẽ không thể biên dịch thành công.

- Có một vài cách đơn giản để khắc phục lỗi này:\
  **1. Xóa bỏ biến không sử dụng:**\
    Nếu biến `x` thực sự không được sử dụng, cách dễ nhất là xóa bỏ định nghĩa của nó (hoặc chú thích nó bằng `//`). Xóa bỏ biến không sử dụng sẽ không ảnh hưởng đến chương trình.
  
  **2. Sử dụng biến ở một nơi nào đó:**
  >```
  >#include <iostream>
  >
  >int main()
  >{
  >  int x { 5 };
  >
  >  std::cout << x; // Biến x được sử dụng
  >
  >  return 0;
  >
  >}
  >
  >```

    Tuy nhiên, cách này yêu cầu viết thêm code để sử dụng biến và có thể ảnh hưởng đến logic ban đầu của chương trình.






### **Thuộc tính `[[maybe_unused]]` trong `C++17`**


**Trường hợp không mong muốn xóa bỏ hoặc sử dụng biến:**
- Trong một số trường hợp, cả hai cách xử lý ở trên (xóa bỏ biến hoặc sử dụng biến) đều không mong muốn. Ví dụ, giả sử chúng ta có một nhóm các hằng số toán học/vật lý được sử dụng trong nhiều chương trình khác nhau:
>```
>int main()
>{
>    double pi { 3.14159 };
>    double gravity { 9.8 };
>    double phi { 1.61803 };
>
>    // Giả sử một số hằng số được sử dụng, một số không
>
>    return 0;
>}
>```
- Nếu chúng ta sử dụng các hằng số này thường xuyên, có thể chúng ta sẽ lưu chúng ở một nơi nào đó và sao chép/dán/nhập khẩu tất cả chúng cùng nhau.
- Tuy nhiên, trong bất kỳ chương trình nào mà chúng ta không sử dụng tất cả các giá trị này, trình biên dịch sẽ phàn nàn về mỗi biến không được sử dụng thực tế. Mặc dù chúng ta có thể xóa hoặc chú thích từng biến không sử dụng cho mỗi chương trình, nhưng điều này tốn thời gian và công sức. Và sau này nếu cần đến một biến đã xóa trước đó, chúng ta sẽ phải quay lại và thêm lại nó.

**Thuộc tính `[[maybe_unused]]`**
- Để giải quyết những trường hợp như vậy, `C++17` giới thiệu thuộc tính `[[maybe_unused]]`, cho phép chúng ta thông báo cho trình biên dịch rằng việc một biến không được sử dụng là chấp nhận được. Trình biên dịch sẽ không tạo ra cảnh báo về biến không sử dụng cho các biến được đánh dấu bằng thuộc tính này.
- Chương trình sau đây sẽ không tạo ra cảnh báo/lỗi:
>```
>int main()
>{
>    [[maybe_unused]] double pi { 3.14159 };
>    [[maybe_unused]] double gravity { 9.8 };
>    [[maybe_unused]] double phi { 1.61803 };
>
>    // Các biến ở trên sẽ không tạo ra cảnh báo về biến không sử dụng
>
>    return 0;
>}
>```

Ngoài ra, trình biên dịch có thể tối ưu hóa các biến này ra khỏi chương trình, vì vậy chúng không ảnh hưởng đến hiệu suất.
