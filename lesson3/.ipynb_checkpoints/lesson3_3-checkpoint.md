## **Bài 3.3: <u>Chiến lược gỡ lỗi</u>**

Trong quá trình gỡ lỗi chương trình, trong hầu hết các trường hợp, phần lớn thời gian của bạn sẽ được dành để cố gắng tìm ra vị trí thực sự của lỗi. Khi sự cố được tìm thấy, các bước còn lại (khắc phục sự cố và xác nhận rằng sự cố đã được khắc phục) thường đơn giản hơn nhiều so với việc tìm ra lỗi.

Trong bài học này, chúng ta sẽ bắt đầu khám phá cách tìm lỗi.

### **Tìm ra vấn đề thông qua kiểm tra mã**

Giả sử bạn đã nhận thấy một vấn đề và bạn muốn theo dõi nguyên nhân của vấn đề cụ thể đó. Trong nhiều trường hợp (đặc biệt là trong các chương trình nhỏ hơn), chúng ta có thể nhanh chóng xác định được vị trí tiềm ẩn của sự cố.

Xem xét đoạn mã sau:

>```
>int main()
>{
>    getNames(); // yêu cầu người dùng nhập một loạt tên
>    sortNames(); // sắp xếp chúng theo thứ tự bảng chữ cái
>    printNames(); // in danh sách tên đã được sắp xếp
>
>    return 0;
>}
>```

Nếu bạn mong đợi chương trình này in ra các tên theo thứ tự bảng chữ cái, nhưng thay vào đó nó lại in ra theo thứ tự ngược lại, thì vấn đề có thể nằm ở hàm `sortNames`. Trong trường hợp bạn có thể thu hẹp vấn đề xuống một hàm cụ thể, bạn có thể phát hiện ra vấn đề chỉ bằng cách nhìn vào mã.

Tuy nhiên, khi chương trình trở nên phức tạp hơn, việc tìm kiếm vấn đề bằng cách kiểm tra mã cũng trở nên phức tạp hơn.

Thứ nhất, có nhiều mã hơn để xem xét. Xem xét từng dòng code trong một chương trình dài hàng nghìn dòng có thể mất rất nhiều thời gian (chưa kể nó cực kỳ nhàm chán). Thứ hai, bản thân mã có xu hướng phức tạp hơn, với nhiều vị trí tiềm ẩn hơn để xảy ra lỗi. Thứ ba, hành vi của mã có thể không cung cấp cho bạn nhiều manh mối về việc mọi thứ đang diễn ra sai ở đâu. Nếu bạn viết một chương trình để đưa ra các đề xuất về cổ phiếu và nó thực sự không xuất ra bất kỳ nội dung gì, thì bạn có thể sẽ không có nhiều manh mối để bắt đầu tìm kiếm vấn đề.

Cuối cùng, lỗi có thể do đưa ra những giả định sai lầm. Gần như không thể phát hiện trực quan một lỗi do đưa ra giả định sai lầm, bởi vì bạn có thể sẽ đưa ra cùng một giả định sai lầm khi kiểm tra mã và không nhận thấy lỗi. Vì vậy, nếu chúng ta có một sự cố mà chúng ta không thể tìm thấy thông qua kiểm tra mã, làm thế nào để chúng ta tìm thấy nó?

### **Tìm ra vấn đề thông qua việc chạy chương trình**

May mắn thay, nếu chúng ta không thể tìm thấy sự cố thông qua kiểm tra mã, thì còn một cách khác mà chúng ta có thể thực hiện: chúng ta có thể theo dõi hành vi của chương trình khi nó chạy và cố gắng chẩn đoán sự cố từ đó. Cách tiếp cận này có thể được khái quát thành:

1. Tìm cách tái tạo sự cố
2. Chạy chương trình và thu thập thông tin để thu hẹp phạm vi nơi xảy ra sự cố
3. Lặp lại bước trước cho đến khi bạn tìm thấy sự cố

Trong phần còn lại của chương này, chúng tôi sẽ thảo luận về các kỹ thuật để hỗ trợ cách tiếp cận này.

### **Tái tạo sự cố**

Bước đầu tiên và quan trọng nhất trong việc tìm kiếm vấn đề là khả năng tái tạo vấn đề. Tái tạo sự cố có nghĩa là khiến sự cố xuất hiện một cách nhất quán. Lý do rất đơn giản: rất khó để tìm ra vấn đề trừ khi bạn có thể quan sát thấy nó xảy ra.

Quay trở lại phép loại suy về máy phân phối đá của chúng ta - giả sử một ngày nào đó bạn của bạn nói với bạn rằng máy phân phối đá của bạn không hoạt động. Bạn đến xem nó, và nó hoạt động tốt. Làm thế nào để bạn chẩn đoán vấn đề? Sẽ rất khó khăn. Tuy nhiên, nếu bạn thực sự có thể thấy sự cố của máy phân phối đá không hoạt động, thì bạn có thể bắt đầu chẩn đoán lý do tại sao nó không hoạt động hiệu quả hơn nhiều.

Nếu sự cố phần mềm là hiển nhiên (ví dụ: chương trình bị treo ở cùng một chỗ mỗi lần bạn chạy nó) thì việc tái tạo sự cố có thể rất đơn giản. Tuy nhiên, đôi khi việc tái tạo sự cố có thể khó khăn hơn nhiều. Vấn đề chỉ có thể xảy ra trên một số máy tính nhất định hoặc trong những trường hợp cụ thể (ví dụ: khi người dùng nhập một đầu vào nhất định). Trong những trường hợp như vậy, việc tạo ra một tập hợp các bước tái tạo có thể hữu ích. **Bước tái tạo** (**Reproduction steps**) là một danh sách các bước rõ ràng và chính xác có thể được thực hiện để khiến sự cố tái diễn lại với mức độ dự đoán cao. Mục tiêu là có thể khiến sự cố tái diễn càng nhiều càng tốt, vì vậy chúng ta có thể chạy chương trình nhiều lần và tìm kiếm manh mối để xác định nguyên nhân gây ra sự cố. Nếu sự cố có thể được tái tạo 100% thời gian thì đó là điều lý tưởng, nhưng khả năng tái tạo dưới 100% cũng có thể chấp nhận được. Một sự cố chỉ xảy ra 50% thời gian đơn giản có nghĩa là nó sẽ mất gấp đôi thời gian để chẩn đoán sự cố, vì một nửa thời gian chương trình sẽ không hiển thị sự cố và do đó không cung cấp bất kỳ thông tin chẩn đoán hữu ích nào.

### **Thu hẹp phạm vi sự cố**

Khi chúng ta đã có thể tái tạo vấn đề một cách hợp lý, bước tiếp theo là xác định vị trí trong code nơi xảy ra vấn đề. Dựa trên bản chất của vấn đề, điều này có thể dễ dàng hoặc khó khăn. Vì mục đích minh họa, giả sử chúng ta không có nhiều ý tưởng về vị trí thực sự của vấn đề. Làm thế nào để chúng ta tìm thấy nó?

Để minh họa cho việc thu hẹp phạm vi vấn đề trong quá trình gỡ lỗi, hãy cùng chơi một trò chơi đơn giản gọi là Hi-Lo. Trong trò chơi này, tôi sẽ nghĩ đến một số ngẫu nhiên từ 1 đến 10, và bạn sẽ lần lượt đưa ra các phán đoán về số đó. Sau mỗi phán đoán, tôi sẽ cho bạn biết liệu số bạn đoán là cao hơn, thấp hơn hay bằng số tôi đang nghĩ.

Hãy tưởng tượng bạn đang chơi Hi-Lo với một người bạn:

>**Bạn:** 5
>
>**Bạn của bạn:** Quá thấp!
>
>**Bạn:** 8
>
>**Bạn của bạn:** Quá cao!
>
>**Bạn:** 6
>
>**Bạn của bạn:** Vẫn thấp!
>
>**Bạn:** 7
>
>**Bạn của bạn:** Chính xác!

Trong trò chơi ở trên, bạn không cần phải đoán mọi số để tìm ra số tôi đang nghĩ. Thông qua quá trình đưa ra các phán đoán và xem xét thông tin bạn học được từ mỗi phán đoán, bạn có thể "thu hẹp" phạm vi tìm kiếm số chính xác chỉ với một vài lần đoán (nếu bạn sử dụng chiến lược tối ưu, bạn luôn có thể tìm ra số tôi đang nghĩ trong 4 lần đoán trở xuống).

Quá trình này tương tự như cách thu hẹp phạm vi vấn đề trong gỡ lỗi chương trình.

- **Bắt đầu với phạm vi rộng:** Khi bắt đầu gỡ lỗi, bạn thường không biết chính xác vị trí xảy ra lỗi. Tuy nhiên, bạn biết rằng lỗi phải nằm ở đâu đó trong đoạn mã được thực thi giữa đầu chương trình và điểm chương trình hiển thị triệu chứng không chính xác đầu tiên mà bạn có thể quan sát được.

- **Thu hẹp phạm vi:** Dựa trên thông tin thu thập được khi chạy chương trình (ví dụ: thông báo lỗi, giá trị biến), bạn có thể dần dần thu hẹp phạm vi tìm kiếm vị trí lỗi.

- **Sử dụng các kỹ thuật gỡ lỗi:** Có nhiều kỹ thuật gỡ lỗi khác nhau có thể giúp bạn thu hẹp phạm vi vấn đề, chẳng hạn như đặt điểm ngắt, theo dõi biến và phân tích luồng chương trình.

**Mục tiêu:** Việc thu hẹp phạm vi vấn đề giúp bạn xác định vị trí lỗi một cách nhanh chóng và hiệu quả, tiết kiệm thời gian và công sức cho quá trình gỡ lỗi.

Phép chơi Hi-Lo tuy hữu ích nhưng không hoàn toàn chính xác khi áp dụng vào việc gỡ lỗi chương trình. Đôi khi, chúng ta có thể loại bỏ hoàn toàn một số đoạn mã khỏi quá trình xem xét mà không thu được bất kỳ thông tin nào về việc vấn đề thực sự nằm trước hay sau đoạn mã đó.

Chúng tôi sẽ trình bày các ví dụ về cả ba trường hợp này trong bài học tiếp theo.

Cuối cùng, với đủ nhiều lần phán đoán và một số kỹ thuật tốt, chúng ta có thể xác định chính xác dòng lệnh gây ra sự cố! Nếu chúng ta đã đưa ra bất kỳ giả định sai lầm nào, điều này sẽ giúp chúng ta phát hiện ra vị trí sai lầm. Khi bạn đã loại trừ tất cả các khả năng khác, thì điều duy nhất còn lại chắc chắn phải là nguyên nhân gây ra sự cố. Sau đó, vấn đề chỉ còn là hiểu tại sao.

Chiến lược phán đoán nào bạn muốn sử dụng phụ thuộc vào bạn - chiến lược tốt nhất phụ thuộc vào loại lỗi, vì vậy bạn có thể muốn thử nhiều cách tiếp cận khác nhau để thu hẹp vấn đề. Khi bạn có thêm kinh nghiệm trong việc gỡ lỗi sự cố, trực giác của bạn sẽ giúp bạn định hướng.

Vậy làm thế nào để chúng ta "đưa ra những phán đoán"? Có nhiều cách để thực hiện việc này. Chúng ta sẽ bắt đầu với một số cách tiếp cận đơn giản trong chương tiếp theo, sau đó chúng ta sẽ xây dựng dựa trên những cách này và khám phá các cách khác trong các chương sau.
