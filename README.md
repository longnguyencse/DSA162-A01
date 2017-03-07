#Bài tập lớn 01
##Mô tả
Giao thông đường bộ Việt Nam là một tổ hợp gồm nhiều loại xe, nhiều kích cỡ 
hoạt động trên cùng một tuyến đường. Sự va chạm, xung đột, tai nạn rất dễ 
xảy ra. Đặc biệt, tại các đô thị lớn như thành phố Hồ Chí Minh (Tp.HCM) có 
không ít lái xe do ý thức chấp hành luật giao thông kém nên đã xuất hiện tình 
trạng phóng nhanh vượt ẩu, lạng lách, đánh võng, lấn làn gây bức xúc trong 
dư luận, trở thành nỗi ám ảnh của hành khách và người tham gia giao thông. 
Các hành vi này chẳng những làm giảm an toàn giao thông mà còn là yếu tố 
chính góp phần ùn tắc giao thông, đặc biệt là tại một thành phố lớn như Tp.HCM. 

Đại đa số đều đồng ý quan điểm rằng phát triển tốt giao thông công cộng để 
phục vụ người dân là một yếu tố quan trọng và hữu hiệu góp phần giải quyết 
các vấn đề trên, trong đó bài toán cơ sở là quản lý tốt các phương tiện vận tải 
công cộng. Việc quản lý này sẽ giúp kiểm soát các hành vi giao thông của các 
phương tiện vận tải công cộng, nhằm nâng cao ý thức và hình ảnh của nhóm 
phương tiện này.

Về mặt qui trình, hiện tại các phương tiện công cộng tại Tp. HCM được quản lý 
bởi cả doanh nghiệp vận tải công cộng và tư nhân, được gọi là các đại lý. Ví dụ 
về xe buýt công cộng, để vận hành từng tuyến đường xe buýt, các đại lý được 
tham gia đấu thầu. Dựa trên các tiêu chí đã được đặt ra công khai cho từng 
tuyến xe buýt, Trung tâm quản lý và hoạt động cho giao thông công cộng 
(TT Điều hành), đại diện Sở Giao thông Vận tải Tp.HCM, sẽ lựa chọn chỉ một 
đại lý cho một tuyến xe buýt. Các đại lý trúng thầu sẽ chịu trách nhiệm cung cấp 
và điều hành hoạt động của các xe buýt trên tuyến. Hoạt động hằng ngày và 
các thông tin điều khiển của xe buýt phải báo cáo đến cơ quan trước khi xe lăn bánh.

Mỗi xe buýt và cũng như hầu hết các phương tiện vận tải công cộng hiện nay 
được trang bị hộp đen thiết bị GPS (dùng để lưu trữ hành trình của các xe). 
Trong thực tế, nhu cầu về số lượng phương tiện vận tải đa dạng và tùy thuộc 
vào khoảng thời gian trong ngày. 

Trong bài tập lớn này, chúng ta sẽ phát triển một module cơ bản để quản lý các 
thông tin GPS lưu trữ được từ hành trình các phương tiện vận tải.

##Yêu cầu
Trong bài tập lớn này, sinh viên sẽ được cung cấp hai file trong đó
- Một file chứa dữ liệu nhập, bao gồm các mẫu thông tin về trạng thái của phương tiện vận tải tại một thời điểm. Các mẫu dữ liệu nhập này đều được lưu trữ và biểu diễn dưới dạng danh sách liên kết (linked list).
- Một file chứa một (hoặc một tập các) yêu cầu truy xuất. Chi tiết cụ thể yêu cầu công việc sinh viên phải làm sẽ mô tả trong phần 4.

###Dữ liệu nhập
Dữ liệu nhập của chương trình được chứa trong file input như sau:

| # | Nội dung |
|---|:---------|
|1| 1B03755,1,0000001234567890,0.0,1.472989878E9,106.781668333333,10.65749,0.0,348.0,0,1,0,0,0,1,0.0,0.0 |
|2| 61C21884,1,,0.0,1.472989881E9,106.411811666667,11.1932933333333,0.0,288.0,0,0,0,0,0,0,0.0,0.0 |
|3| 51B14725,1,0000001234567891,0.0,1.472989881E9,106.689196666667,10.7733133333333,0.0,30.0,1,1,0,0,0,0,0.0,0.0 |
|4| 51C65728,1,0000,0.0,1.472989881E9,106.6605,10.8074,0.0,0.0,0,0,0,0,0,0,0.0,0.0 |

Mỗi dòng trong file sẽ chứa một loạt các thông tin mô tả như sau:
- Phần tử đầu tiên: biển số xe (vehicle ID).
- Phần tử thứ 5: thời điểm xe gửi tín hiệu GPS (timestamp).
- Phần tử thứ 6: kinh độ (longitude).
- Phần tử thứ 7: vĩ độ (latitude).

Ngoài ra, xe được xem là đang dừng khi toạ độ tại thời điểm hiện tại so với thời điểm trước đó cách nhau 
 dưới 5m.

###Dữ liệu xuất
Dữ liệu sinh viên xuất ra cần tuân thủ các quy tắc sau:
 + Số nguyên: không cần định dạng
 + Số thực: độ chính xác 3 chữ số
 + Các dòng dữ liệu: với mỗi request, sinh viên xuất ra
 thông tin trên cùng một dòng, cách nhau bởi khoảng trắng.
 + Nếu dữ liệu gồm nhiều dòng thì mỗi dòng xuất thông tin của một đối tượng
 (vd: dữ liệu của cùng một bus). 
 + Nếu request là dạng command, sinh viên xuất 
 ra `nội dung request`: `Succeed`/`Failed`.

##Các yêu cầu truy xuất
Các yêu cầu có thể được xử lý trên database.

| Mã sự kiện | Ý nghĩa |
| ---------- | ------- |
| 0          | số lượng phương tiện đang có trong database | 
| 1A         | phương tiện vận tải được lưu trữ đầu tiên   |
| 1B         | phương tiện vận tải được lưu trữ cuối cùng  |
| 2AXXYXXXXX | tọa độ lat được lưu trữ đầu tiên của xe mang biển số `XXYXXXXX` |
| 2BXXYXXXXX | tọa độ long được lưu trữ đầu tiên của xe mang biển số `XXYXXXXX` |
| 3AXXYXXXXX | tọa độ lat được lưu trữ cuối cùng của xe mang biển số `XXYXXXXX` |
| 3BXXYXXXXX | tọa độ long được lưu trữ cuối cùng của xe mang biển số `XXYXXXXX` |
| 4AXXYXXXXX | thời điểm bắt đầu lưu trữ của xe mang biển số `XXYXXXXX` |
| 4BXXYXXXXX | thời điểm kết thúc lưu trữ của xe mang biển số `XXYXXXXX` |
| 5AXXYXXXXX | số lượng thông tin lưu trữ của xe mang biển số `XXYXXXXX` (số bảng ghi trong database)|
| 5BXXYXXXXX | độ dài hành trình lưu trữ của xe mang biển số `XXYXXXXX` (đơn vị tính theo km)|
| 5CXXYXXXXX | thời lượng hành trình lưu trữ của xe mang biển số `XXYXXXXX` (tính từ lúc bắt đàu di chuyển đến khi kết thúc hành trình)|
| 6AXXYXXXXX | điểm dừng đầu tiên của xe mang biển số `XXYXXXXX`: xuất cặp toạ độ (latitude, longtitude)|
| 6BXXYXXXXX | điểm dừng cuối cùng của xe mang biển số `XXYXXXXX`: xuất cặp toạ độ (latitude, longtitude)|
| 6CXXYXXXXX | thời lượng dừng lâu nhất của xe mang biển số `XXYXXXXX` |
| 6DXXYXXXXX | khoảng cách trung bình khi thu thập dữ liệu của xe mang biển số `XXYXXXXX` |
| 7A         | thời lượng dừng lâu nhất của tất cả các phương tiện vận tải trong CSDL |
| 7B         | số lượng record của tất cả các phương tiện vận tải |
| 7C         | phương tiện vận tải có số lượng record nhiều nhất |
| 7D         | phương tiện vận tải có số lượng record ít nhất |
| 7E         | phương tiện vận tải có tổng thời gian hành trình lâu nhất |
| 7F         | phương tiện vận tải có vận tốc trung bình nhanh nhất |
| 7G         | số lượng phương tiện vận tải luôn di chuyển và không dừng |
| 7H         | khoảng cách trung bình khi thu thập dữ liệu của tất cả các phương tiện vận tải |
| 7I         | phương tiện vận tải có hành trình dài nhất |
| 7J         | phương tiện vận tải có hành trình ngắn nhất |
| 8XXYXXXXX  | xóa các record của xe mang biển số `XXYXXXXX` |
**Lưu ý: nếu có nhiều kết quả có thể trả về thì chọn kết quả đầu tiên theo thứ tự lưu 
trong dữ liệu đầu vào.**

**Ví dụ:** với file dữ liệu mẫu được cung cấp, output của bạn sẽ như sau

| |
| ------------- |
| 0: 100
| 1A: 51B03755
| 1B: 51B07604
| 2A53N9672: 10.806
| 2B53N9672: 106.817
| 3A53N9672: 10.806
| 3B53N9672: 106.817
| 4A53N9672: 2016-09-04 11:51:22
| 4B53N9672: 2016-09-04 11:51:22
| 5A53N9672: 1
| 5B53N9672: 0.000
| 5C53N9672: 0
| 6A53N9672: Failed
| 6B53N9672: Failed
| 6C53N9672: Failed
| 6D53N9672: Failed
| 7A: 0
| 7B: 100
| 7C: 51B03755
| 7D: 51B03755
| 7E: 51B03755
| 7F: Failed
| 7G: 0
| 7H: Failed
| 7I: 51B03755
| 7J: 51B03755
| 82A53N9672: Failed

##Hiện thực
**Sinh viên được cung cấp các file sau:**
 - main.cpp: mã nguồn chính của chương trình
 - listLib.h: file chứa định nghĩa thư viện danh sách liên kết
 - dbLib.h: file header chứa prototype cần thiết để quản lý database
 - dbLib.cpp: mã nguồn hiện thực các chức năng quản lý database
 - eventLib.h: file header chứa các prototype cần thiết để quản lý các sự kiện
 - eventLib.cpp: mã nguồn hiện thực các hàm xử lý sự kiện

__Sinh viên được cho các hàm sau:__
 - distanceEarth: tính khoảng cách giữa 2 điểm trên mặt đất với 
 toạ độ (latitude, longitude) cho trước.
 - loadBusDB: đọc file và lấy dữ liệu bus vào danh sách
 - parseBusInfo: đọc thông tin bus từ dòng dữ liệu
 - strPrintTime: in thời gian ra một chuỗi theo định dạng yêu cầu

Đối với file thư viện listLib.h, sinh viên được cung cấp sẵn định 
nghĩa cơ bản. Ngoài ra, _để build được chương trình hoàn chỉnh, sinh viên
cần hoàn thiện các hàm còn lại trong danh sách_.

__processData.cpp__
Sinh viên hiện thực việc xử lý các yêu cầu thông qua hàm __*processEvent*__.
Không được thay đổi prototype của hàm này.

Sinh viên được phép tuỳ biến, chỉnh sửa `listLib.h` và `processData.cpp`.

**Sinh viên không được sử dụng các thư viện nào khác ngoài các thư viện đã được 
dùng trong code mẫu.**
## Build
Sinh viên thực hiện build bằng lệnh `make` từ command line trên Linux
và chạy file `a01`. Cú pháp trên linux như sau:
> `./a01 event.txt input1.txt`

trong đó `event.txt` là file chứa danh sách các sự kiện, cách nhau bởi 
  khoảng trắng hoặc ký tự xuống dòng.
  `input1.txt` là file dữ liệu xe bus, sinh viên có thể thử nghiệm với 
  các file dữ liệu khác nhau. 

Đối với các bạn dùng VisualStudio trên Windows, các bạn có thể tạo một 
project và thêm các file mã nguồn vào. Nếu không bạn có thể sử dụng hệ 
thống CMake để tự sinh project VS cho mình.
 