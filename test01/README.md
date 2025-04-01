# TEST 1: bootstrapping
## boot.S
- Ban đầu khởi động, cả 4 lõi của CPU sẽ cùng chạy một chương trình (trỏ đến địa chỉ giống nhau).
- Khi khởi động, sẽ chỉ cho lõi chính hoạt động (core 0).
- Các lõi sẽ có các ID khác nhau đại diện cho lõi ở thanh ghi hệ thống mpidr_el1.
- Nếu số hiệu lõi chính là 0 thì sẽ hoạt động khởi tạo cho chương trình tại đây, còn nếu số hiệu lõi khác 0 thì sẽ đưa các lõi vào hàng đợi.
- Quá trình khởi tạo, đưa địa chỉ bắt đầu chương trình và thanh ghi stack pointer (SP).
- Lấy địa chỉ đầu và kích thước của bss được khởi tạo. Khi biên dịch, các biến được khởi tạo nhưng chưa gán giá trị sẽ được lưu tại vùng bss. Do đó, tại đây sẽ gán các giá trị của các biến đó bằng 0 (lưu giá trị tại thanh ghi chứa biến bss thành 0, sau đó tăng kích thước theo số lượng căn chỉnh để đến địa chỉ của biến bss tiếp theo).
- Sau khi thực hiện lần lượt các bước trên xong thì sẽ nhảy đến chương trình C (được thực hiện bằng chương trình C).

## linker.ld
- Chương trình ở đây chủ yếu để tổ chức bộ nhớ
- Địa chỉ bắt đầu là 0x80000, đây là địa chỉ khởi tạo cho bootloader hoặc firmware.
- Cấp phát cho toàn bộ chương trình một kích cỡ bộ nhớ, các phần .text .data .bss sẽ khởi tạo và sử dụng lần lượt theo thứ tự địa chỉ.
- linker.ld sẽ căn chỉnh cho các dữ liệu đó là 8 bytes, khi khởi tạo sẽ đánh dấu điểm đầu và điểm kết thúc cho từng phân đoạn để sử dụng về sau.
- Cấp quyền truy cập cho các phân đoạn (đọc-ghi-thực thi).



