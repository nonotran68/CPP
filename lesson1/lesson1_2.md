## **Bài 1.2: <u>Chú thích</u>**

- Chú thích là những dòng văn bản được thêm vào mã C++ để giúp con người hiểu rõ hơn về mã. Chúng bị trình biên dịch bỏ qua và không ảnh hưởng đến cách chương trình chạy.
- Trong C++ có hai kiểu chú thích khác nhau, cả hai đều phục vụ cùng một mục đích: giúp các lập trình viên ghi lại mã theo một cách nào đó.
    - **Chú thích một dòng**: Bắt đầu bằng `//` và kết thúc ở cuối dòng.
    > <u>Ví dụ:</u>
    > 
    > `std::cout << "Hello world!"; // Everything from here to the end of the line is ignored`
    - **Chú thích nhiều dòng**: Bắt đầu bằng `/*` và kết thúc bằng `*/`.
    > <u>Ví dụ:</u>
    > 
    > `/* Đây là chú thích nhiều dòng`\
    > `Có thể bao gồm nhiều dòng */`
- Chú thích có thể được sử dụng để:
    - Giải thích mục đích của một đoạn mã.
    - Ghi chú về cách thức hoạt động của một đoạn mã.
    - Ghi chú về các thay đổi đã được thực hiện đối với mã.
    - Ghi chú về các vấn đề tiềm ẩn với mã.
- Dưới đây là một số mẹo để sử dụng chú thích hiệu quả:
    - Viết chú thích rõ ràng và súc tích.
    - Sử dụng chú thích để giải thích những phần mã phức tạp.
    - Sử dụng chú thích để ghi chú về các thay đổi quan trọng đối với mã.
    - Sử dụng chú thích để ghi chú về các vấn đề tiềm ẩn với mã.
    - Tránh sử dụng chú thích để lặp lại thông tin hiển nhiên trong mã.

- Ví dụ về chú thích tốt:
  - Giải thích mục đích của đoạn mã:
  ```
    // Hàm này tính diện tích của một hình vuông
    int square_area(int side_length) {
      return side_length * side_length;
    }
  ```
  - Ghi chú về cách thức hoạt động của một đoạn mã:
  ```
    // Vòng lặp này in ra các số từ 1 đến 10
    for (int i = 1; i <= 10; i++) {
      std::cout << i << std::endl;
    }

  ```
  - Ghi chú về các thay đổi đã được thực hiện đối với mã:
  ```
    // Đã sửa lỗi trong hàm `square_area`
    // Hàm hiện hoạt động chính xác cho tất cả các giá trị đầu vào
  ```
  - Ghi chú về các vấn đề tiềm ẩn với mã:
  ```
    // Lưu ý: Hàm này có thể gây tràn bộ nhớ nếu `n` quá lớn
    int factorial(int n) {
      if (n == 0) {
        return 1;
      } else {
        return n * factorial(n - 1);
      }
    }

  ```
- Chú thích tệ:
    - Lặp lại thông tin hiển nhiên trong mã:
    ```
        // int i = 1; // Biến i được khởi tạo với giá trị 1

    ```
    - Chú thích không rõ ràng:
    ```
    // Hàm này thực hiện một số phép toán
        int do_something(int a, int b) {
          // ...
        }
    ```
    - Chú thích không hữu ích:
    ```
        // Đây là một hàm
        void my_function() {
          // ...
        }
    ```
- **Chú thích tốt giúp cho mã C++ của bạn dễ đọc và dễ hiểu hơn.**

