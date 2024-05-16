## **Bài 2.3: <u>Hàm `void` (Hàm Không Trả Giá Trị)</u>**

Trong bài học trước **(2.1 - Giới thiệu về Hàm)**, chúng ta đã thấy cú pháp cho định nghĩa một hàm trông như thế này:

>```
>returnType tên_hàm() // tên_hàm được thay thế bằng tên hàm của bạn
>{
>  // Code của bạn ở đây
>}
>```

Mặc dù chúng tôi đã trình bày các ví dụ về hàm có kiểu trả về `void`, nhưng chúng tôi không thảo luận về ý nghĩa của nó. Trong bài học này, chúng ta sẽ khám phá các hàm có kiểu trả về `void`.

### **Giá trị trả về `void`**

Hàm không nhất thiết phải trả về giá trị cho chương trình gọi nó. Để thông báo cho trình biên dịch rằng một hàm không trả về giá trị, kiểu trả về `void` được sử dụng. Ví dụ:

>```
>#include <iostream>
>
>// void nghĩa là hàm không trả về giá trị cho hàm gọi
>void printHi()
>{
>  std::cout << "Hi" << '\n';
>
>  // Hàm này không trả về giá trị nên không cần câu lệnh return
>}
>
>int main()
>{
>  printHi(); // ổn: hàm printHi() được gọi, không có giá trị được trả về
>
>  return 0;
>}
>```

Trong ví dụ trên, hàm `printHi` có một hành vi có nghĩa (nó in ra `“Hi”`) nhưng nó không cần trả về bất cứ thứ gì cho chương trình gọi. Do đó, `printHi` được đặt kiểu trả về là `void`.

Khi `main` gọi `printHi`, mã trong `printHi` được thực thi và “Hi” được in ra. Khi kết thúc `printHi`, quyền điều khiển trở lại `main` và chương trình tiếp tục.

Một hàm không trả về giá trị được gọi là hàm không trả giá trị (hoặc hàm `void`).

### **Hàm `void` không cần câu lệnh `return`**

Một hàm `void` sẽ tự động nhảy về hàm gọi ở cuối hàm. Không cần câu lệnh `return`.

Câu lệnh `return` (với không có giá trị trả về nào, hay `return` trống) có thể được sử dụng trong một hàm `void` - một câu lệnh như vậy sẽ khiến hàm nhảy về hàm gọi tại điểm mà câu lệnh `return` được thực thi. Điều này cũng giống như những gì xảy ra ở cuối hàm. Do đó, việc đặt một câu lệnh `return` trống ở cuối hàm `void` là thừa:

>```
>#include <iostream>
>
>// void nghĩa là hàm không trả về giá trị cho chương trình gọi
>void printHi()
>{
>  std::cout << "Hi" << '\n';
>
>  return; // yêu cầu trình biên dịch trả về cho hàm gọi - điều này thừa vì lệnh return; sẽ luôn xảy ra ở cuối hàm!
>} // hàm sẽ trả về cho chương trình gọi tại đây
>
>int main()
>{
>  printHi();
>
>  return 0;
>}
>```

>**Thực hành tốt nhất**<br>
>Không đặt câu lệnh `return` ở cuối hàm `void`.

### **Hàm `void` không thể sử dụng trong biểu thức yêu cầu giá trị**

Một số loại biểu thức yêu cầu giá trị. Ví dụ:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 5; // ok: 5 is a literal value that we're sending to the console to be printed
>    std::cout << ;  // compile error: no value provided
>
>    return 0;
>}
>```

Trong chương trình trên, giá trị cần in phải được cung cấp ở phía bên phải của `std::cout <<`. Nếu không cung cấp giá trị, trình biên dịch sẽ tạo ra lỗi cú pháp. Vì lần gọi thứ hai đến `std::cout` không cung cấp giá trị để in ra, điều này gây ra lỗi.

Bây giờ hãy xem xét chương trình sau:

>```
>#include <iostream>
>
>// void nghĩa là hàm không trả về giá trị cho chương trình gọi
>void printHi()
>{
>  std::cout << "Hi" << '\n';
>}
>
>int main()
>{
>  printHi(); // ổn: hàm printHi() được gọi, không có giá trị được trả về
>
>  std::cout << printHi(); // lỗi biên dịch
>
>  return 0;
>}
>```

Lần gọi đầu tiên đến `printHi()` được gọi trong một bối cảnh không yêu cầu giá trị. Vì hàm không trả về giá trị nên điều này là ổn.

Lần gọi hàm thứ hai đến hàm `printHi()` thậm chí sẽ không được biên dịch. Hàm `printHi` có kiểu trả về là `void`, nghĩa là nó không trả về giá trị. Tuy nhiên, câu lệnh này đang cố gắng gửi giá trị trả về của `printHi` đến `std::cout` để in ra. `std::cout` không biết cách xử lý điều này (nó sẽ xuất ra giá trị gì?). Do đó, trình biên dịch sẽ đánh dấu đây là lỗi. Bạn cần phải chú thích dòng code này để chương trình có thể biên dịch.

>**Mẹo**<br>
>Một số câu lệnh yêu cầu cung cấp giá trị, một số khác thì không.
>
>Khi chúng ta có một câu lệnh chỉ bao gồm một lời gọi hàm (ví dụ như `printHi()` đầu tiên trong ví dụ trên), chúng ta đang gọi một hàm vì hành vi của nó, chứ không phải giá trị trả về của nó. Trong trường hợp này, chúng ta có thể gọi một hàm không trả về giá trị hoặc có thể gọi một hàm trả về giá trị và bỏ qua giá trị trả về đó.
>
>Khi chúng ta gọi một hàm trong bối cảnh yêu cầu giá trị (ví dụ như `std::cout`), thì phải cung cấp một giá trị. Trong ngữ cảnh như vậy, chúng ta chỉ có thể gọi các hàm trả về giá trị.
>
>>```
>>#include <iostream>
>>
>>// Hàm không trả về giá trị
>>void returnNothing()
>>{
>>}
>>
>>// Hàm trả về một giá trị
>>int returnFive()
>>{
>>    return 5;
>>}
>>
>>int main()
>>{
>>    // Khi gọi một hàm riêng lẻ, không yêu cầu giá trị
>>    returnNothing(); // ok: chúng ta có thể gọi một hàm không trả về giá trị
>>    returnFive();    // ok: chúng ta có thể gọi một hàm trả về giá trị và bỏ qua giá trị trả về đó
>>
>>    // Khi gọi một hàm trong bối cảnh yêu cầu giá trị (như std::cout)
>>    std::cout << returnFive();    // ok: chúng ta có thể gọi một hàm trả về giá trị và giá trị đó sẽ được sử dụng
>>    std::cout << returnNothing(); // lỗi biên dịch: chúng ta không thể gọi một hàm trả về void trong ngữ cảnh này
>>
>>    return 0;
>>}
>>```

### **Trả về giá trị từ hàm void gây ra lỗi biên dịch**

Việc cố gắng trả về giá trị từ một hàm không trả về giá trị sẽ dẫn đến lỗi biên dịch:

>```
>void printHi() // Hàm này không trả về giá trị
>{
>    std::cout << "In printHi()" << '\n';
>
>    return 5; // lỗi biên dịch: chúng ta đang cố gắng trả về giá trị
>}
>```
