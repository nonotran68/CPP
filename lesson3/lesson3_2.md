## **Bài 3.2: <u>Quá trình gỡ lỗi</u>**

**Tình huống:** Bạn đã viết một chương trình, nhưng nó không hoạt động chính xác - mã biên dịch tốt, nhưng khi chạy lại cho kết quả không mong đợi. Chắc chắn là có một lỗi logic (semantic error) ở đâu đó. Làm thế nào để tìm ra nó?

Nếu bạn đã tuân theo các thông lệ tốt bằng cách viết từng phần nhỏ của chương trình và kiểm tra nó, thì bạn có thể có một ý tưởng về vị trí của lỗi. Hoặc bạn có thể hoàn toàn không biết gì.

**Nguồn gốc của lỗi:** Tất cả các lỗi đều bắt nguồn từ một tiền đề đơn giản: Điều gì bạn nghĩ là đúng, thì hóa ra lại không đúng. Việc thực sự xác định vị trí của lỗi này có thể rất khó khăn. Trong bài học này, chúng ta sẽ phác thảo quy trình chung để gỡ lỗi chương trình.

**Lưu ý về độ phức tạp:** Do chúng ta chư đề cập nhiều chủ đề C++ cho đến thời điểm này, nên các chương trình ví dụ trong chương này sẽ khá cơ bản. Điều đó có thể khiến một số kỹ thuật mà chúng tôi trình bày ở đây có vẻ quá mức cần thiết. Tuy nhiên, hãy nhớ rằng các kỹ thuật này được thiết kế để sử dụng với các chương trình lớn hơn, phức tạp hơn và sẽ hữu ích hơn trong môi trường như vậy (đó là nơi bạn cần chúng nhất).

### **Cách tiếp cận chung để gỡ lỗi**

Khi một vấn đề được xác định, việc gỡ lỗi thường bao gồm sáu bước:

1. Tìm ra gốc rễ của vấn đề (thường là dòng code không hoạt động).
2. Đảm bảo bạn hiểu tại sao sự cố xảy ra.
3. Xác định cách bạn sẽ khắc phục sự cố.
4. Sửa chữa vấn đề gây ra trục trặc.
5. Kiểm tra lại để đảm bảo vấn đề đã được khắc phục.
6. Kiểm tra lại để đảm bảo không có vấn đề mới phát sinh.

**<u>Ví dụ thực tế:</u>**

Giả sử một buổi tối, bạn đi lấy đá từ ngăn chứa đá trong tủ lạnh. Bạn đặt cốc lên ngăn chứa, nhấn cần gạt và ... không có gì chảy ra. Ồ! Bạn đã phát hiện ra một số khiếm khuyết. Bạn sẽ làm gì? Bạn có thể sẽ bắt đầu một cuộc điều tra để xem liệu bạn có thể xác định được nguyên nhân gốc rễ của vấn đề hay không.

**Tìm ra nguyên nhân gốc rễ:** Vì bạn nghe thấy ngăn chứa đá đang cố gắng lấy đá, nên có thể vấn đề không nằm ở chính cơ chế lấy đá. Vì vậy, bạn mở tủ lạnh và kiểm tra khay đá. Không có đá. Liệu đó có phải là nguyên nhân gốc rễ của vấn đề? Không, đó chỉ là một triệu chứng khác. Sau khi kiểm tra thêm, bạn xác định rằng máy làm đá dường như không tạo ra đá. Vấn đề là do máy làm đá hay do yếu tố khác? Tủ lạnh vẫn lạnh, đường nước không bị tắc, và mọi thứ khác dường như hoạt động bình thường, vì vậy bạn kết luận rằng nguyên nhân gốc rễ là do máy làm đá không hoạt động.

**Hiểu vấn đề:** Điều này đơn giản trong trường hợp này. Một máy làm đá bị hỏng sẽ không tạo ra đá.

**Xác định cách sửa chữa:** Lúc này, bạn có một vài lựa chọn để sửa chữa: Bạn có thể giải quyết vấn đề tạm thời (mua túi đá từ cửa hàng). Bạn có thể cố gắng chẩn đoán thêm máy làm đá, để xem có bộ phận nào có thể sửa chữa được không. Bạn có thể mua một máy làm đá mới và lắp đặt nó thay thế cho máy hiện tại. Hoặc bạn có thể mua một tủ lạnh mới. Bạn quyết định mua một máy làm đá mới.

**Sửa chữa sự cố:** Khi máy làm đá đã đến, bạn tiến hành lắp đặt.

**Kiểm tra lại:** Sau khi bật lại điện và đợi qua đêm, máy làm đá mới của bạn bắt đầu tạo đá. Không có vấn đề mới được phát hiện.

Bây giờ hãy áp dụng quy trình này cho chương trình đơn giản của chúng ta từ bài học trước:
>```
>#include <iostream>
>
>int add(int x, int y) // hàm này có nghĩa là thực hiện phép cộng
>{
>    return x - y; // nhưng nó không thực hiện được do sử dụng sai toán tử
>}
>
>int main()
>{
>    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // đáng ra phải in ra 8, nhưng lại in ra 2
>
>    return 0;
>}
>```

Đoạn code này khá hay ở một điểm: lỗi rất rõ ràng, vì câu trả lời sai được in ra màn hình thông qua dòng 10. Điều đó cung cấp cho chúng ta một điểm khởi đầu cho cuộc điều tra của mình.

**Tìm ra nguyên nhân gốc rễ:** Ở dòng 10, chúng ta có thể thấy rằng chúng ta đang truyền các giá trị cố định cho đối số (`5` và `3`), vì vậy không có chỗ cho sai sót ở đây. Vì các đầu vào của hàm `add` là chính xác, nhưng đầu ra lại không, thì rõ ràng là hàm `add` phải tạo ra giá trị không đúng. Câu lệnh duy nhất trong hàm `add` là câu lệnh `return`, đây chính là thủ phạm. Chúng ta đã tìm thấy dòng có vấn đề. Bây giờ, khi chúng ta đã biết cần tập trung sự chú ý vào đâu, việc nhận thấy rằng chúng ta đang trừ thay vì cộng là điều bạn có thể dễ dàng phát hiện thông qua kiểm tra.

**Hiểu vấn đề:** Trong trường hợp này, việc giá trị sai được tạo ra là điều hiển nhiên - chúng ta đang sử dụng sai toán tử.

**Xác định cách sửa chữa:** Chúng ta chỉ đơn giản là thay đổi toán tử trừ (`-`) thành toán tử cộng (`+`).

**Sửa chữa sự cố:** Thực tế việc này là thay đổi toán tử trừ (`-`) thành toán tử cộng (`+`) và đảm bảo chương trình được biên dịch lại.

**Kiểm tra lại:** Sau khi thực hiện thay đổi, chạy lại chương trình sẽ cho thấy chương trình hiện tại tạo ra giá trị chính xác là `8`. Đối với chương trình đơn giản này, thì đó là tất cả các thử nghiệm cần thiết.

Mặc dù ví dụ này rất đơn giản, nhưng nó minh họa quy trình cơ bản mà bạn sẽ trải qua khi chẩn đoán bất kỳ chương trình nào.
