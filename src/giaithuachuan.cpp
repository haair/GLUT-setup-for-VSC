#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <iomanip>

#define max 100

struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct NhanVien
{
	int msnv;
	char ho[10];
	char ten[30];
	char chucvu[300];
	int phongban;
	int luong;
};

struct DanhSach
{
	NhanVien a[max];
	int n;
};

typedef Date date;
typedef NhanVien nhanvien;
typedef DanhSach danhsach;

void menu();
void nhapngaythang(date &ntn);
void nhap1nv(nhanvien &nv);
void xuat1nv(nhanvien nv);
void xuatngaythang(date ntn);
void nhapdanhsach(danhsach &ds);
void xuatdanhsach(danhsach ds);
int timten(danhsach ds, char *c);
void themnv(danhsach &ds, nhanvien x);
void timNhanVienTheoPhongBan(danhsach ds, int maPhongBan);
void xoanv(danhsach ds, int d);
void sapxep(danhsach ds);
void veTableHeader();
void timNhanVienTheoTen(danhsach, char *ten);

int main()
{
	// danhsach ds;
	// ds.n = 3;
	// strcpy(ds.a[0].ho, "Truong");
	// strcpy(ds.a[0].ten, "Tien Dung");
	// ds.a[0].msnv = 113;
	// ds.a[0].phongban = 1.0f;
	// strcpy(ds.a[0].chucvu, "Giam doc");
	// ds.a[0].luong = 10000.0f;

	// strcpy(ds.a[1].ho, "Dang");
	// strcpy(ds.a[1].ten, "Thanh");
	// ds.a[1].msnv = 114;
	// ds.a[1].phongban = 1.0f;
	// strcpy(ds.a[1].chucvu, "Decor");
	// ds.a[1].luong = 25000.0f;

	// strcpy(ds.a[2].ho, "Nguyen");
	// strcpy(ds.a[2].ten, "Van A");
	// ds.a[2].msnv = 115;
	// ds.a[2].phongban = 2.0f;
	// strcpy(ds.a[2].chucvu, "Lao cong");
	// ds.a[2].luong = 10000.0f;
	// xuatdanhsach(ds);
	menu();
	getch();
}
void menu()
{
	int ch;
	danhsach ds;
	ds.n = 3;
	// nhanvien x;

	strcpy(ds.a[0].ho, "Truong");
	strcpy(ds.a[0].ten, "Tien Dung");
	ds.a[0].msnv = 113;
	ds.a[0].phongban = 1.0f;
	strcpy(ds.a[0].chucvu, "Giam doc");
	ds.a[0].luong = 10000.0f;

	strcpy(ds.a[1].ho, "Dang");
	strcpy(ds.a[1].ten, "Thanh");
	ds.a[1].msnv = 114;
	ds.a[1].phongban = 1.0f;
	strcpy(ds.a[1].chucvu, "Decor");
	ds.a[1].luong = 15000.0f;

	strcpy(ds.a[2].ho, "Nguyen");
	strcpy(ds.a[2].ten, "Van A");
	ds.a[2].msnv = 115;
	ds.a[2].phongban = 2.0f;
	strcpy(ds.a[2].chucvu, "Lao cong");
	ds.a[2].luong = 20000.0f;

	// nhapdanhsach(ds);
	// xuatdanhsach(ds);
	while (true)
	{
		printf("\n\t*******************MENU*********************");
		printf("\n\t**  1. Them vao 1 nhan vien               **");
		printf("\n\t**  2. Tim nhan vien theo phong ban       **");
		printf("\n\t**  3. Tim nhan vien thoe ten             **");
		printf("\n\t**  4. Bang luong cua  nhan vien giam dan **");
		printf("\n\t**  5. Danh sach nhan vien                **");
		printf("\n\t********************************************");
		printf("\n\tChon 1 trong chuc nang tren: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			// printf("\n\tvi tri them: ");
			// scanf("%d", &k);
			// nhap1nv(x);
			// themnv(ds, x, k);
			// printf("\n\t\t\tdanh sach sau khi them");
			// xuatdanhsach(ds);
			nhanvien nv;
			nhap1nv(nv);
			themnv(ds, nv);
			break;
		}
		case 2:
		{
			int maPhongBan;
			printf("\n\tNhap ma phong ban can tim: ");
			scanf("%d", &maPhongBan);
			printf("\n\tKet qua tim kiem: \n");
			timNhanVienTheoPhongBan(ds, maPhongBan);
			break;
		}
		case 3:
		{
			char ten[20];
			printf("\n\tNhap ten can tim: ");
			fflush(stdin);
			gets(ten);
			timNhanVienTheoTen(ds, ten);
			// int b = timten(ds, c);
			// if (timten(ds, c) == -1)
			// 	printf("\nKhong tim thay nhan vien: %s", c);
			// else
			// 	printf("\nTim thay nhan vien thu %d", b + 1);
			break;
		}
		case 4:
		{
			printf("\n\t\t\tDANH SACH LUONG SAU KHI SAP XEP\n");
			sapxep(ds);
			break;
		}
		case 5:
		{
			// printf("\nnhap ma so can xoa: ");
			// scanf("%d", &d);
			// xoanv(ds, d);
			// printf("\n\t\tdanh sach sau khi xoa");
			xuatdanhsach(ds);
			break;
		}
		default:
			printf("\nkhong co chuc nang nay");
			break;
		}
	}
}

void nhapngaythang(date &ntn)
{
	do
	{
		printf("\nnhap vao ngay ");
		scanf("%d", &ntn.ngay);
	} while (ntn.nam > 0 || ntn.ngay > 31);
	do
	{
		printf("\nnhap vao thang ");
		scanf("%d", &ntn.thang);
	} while (ntn.thang < 0 || ntn.thang > 12);
	printf("\nnhap vao nam ");
	scanf("%d", &ntn.nam);
}

void xuatngaythang(date ntn)
{
	printf("%d-", ntn.ngay);
	printf("%d-", ntn.thang);
	printf("%d", ntn.nam);
}

void nhap1nv(nhanvien &nv)
{
	printf("\nnhap vao msnv: ");
	scanf("%d", &nv.msnv);
	printf("\nnhap vao ho: ");
	fflush(stdin);
	gets(nv.ho);
	printf("\nnhap vao ten:");
	fflush(stdin);
	gets(nv.ten);
	printf("\nchuc vu: ");
	fflush(stdin);
	gets(nv.chucvu);
	printf("\nhap vao phong ban: ");
	scanf("%f", &nv.phongban);
	printf("\nhap vao luong: ");
	scanf("%f", &nv.luong);
}

void xuat1nv(nhanvien nv)
{
	// printf("\nma so nhan vien: %d", nv.msnv);
	// printf("\nho: %s", nv.ho);
	// printf("\nten: %s", nv.ten);
	// printf("\nchuc vu: %s", nv.chucvu);
	// printf("\nphongban: %d", nv.phongban);
	// printf("\nluong: %8.2f", nv.luong);

	std::cout << std::setw(10) << std::left << nv.msnv << std::setw(10) << nv.ho << std::setw(15) << nv.ten << std::setw(20) << nv.chucvu << std::setw(15) << nv.phongban << nv.luong << std::endl;
}

void nhapdanhsach(danhsach &ds)
{
	printf("\nnhap so luong nhan vien: ");
	scanf("%d", &ds.n);
	printf("\n\t\t\tnhap thong tin nhan vien");
	for (int i = 0; i < ds.n; i++)
	{
		printf("\n\t\tnhan vien thu %d", i + 1);
		nhap1nv(ds.a[i]);
	}
}

void xuatdanhsach(danhsach ds)
{
	// printf("\n\t\t\tdanh sach nhan vien");
	veTableHeader();
	for (int i = 0; i < ds.n; i++)
	{
		// printf("\n\t\tnhan vien thu %d", i + 1);
		xuat1nv(ds.a[i]);
	}
}

void veTableHeader()
{
	std::cout << std::setw(10) << std::left << std::endl
			  << "MSNV" << std::setw(10) << "Ho" << std::setw(15) << "Ten" << std::setw(20) << "Chuc vu" << std::setw(15) << "Phong ban" << std::setw(30) << "Luong" << std::endl;
	std::cout << "=============================================================================" << std::endl;
}

void themnv(danhsach &ds, nhanvien x)
{
	ds.a[ds.n] = x;
	ds.n++;
}

int timten(danhsach ds, char *c)
{
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.a[i].ten, c) == 0)
		{
			return i;
		}
	}
	return -1;
}
void timNhanVienTheoPhongBan(danhsach ds, int maPhongBan)
{
	veTableHeader();
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.a[i].phongban == maPhongBan)
		{
			xuat1nv(ds.a[i]);
		}
	}
}

void timNhanVienTheoTen(danhsach ds, char *ten)
{
	veTableHeader();
	for (int i = 0; i < ds.n; i++)
	{
		std::string str = ds.a[i].ten;
		if (str.find(ten) != std::string::npos)
		{
			xuat1nv(ds.a[i]);
		}
	}
}

void sapxep(danhsach ds)
{
	for (int i = 0; i < ds.n - 1; i++)
	{
		for (int j = i + 1; j < ds.n; j++)
		{
			if (ds.a[i].luong <= ds.a[j].luong)
			{
				NhanVien temp = ds.a[i];
				ds.a[i] = ds.a[j];
				ds.a[j] = temp;
			}
		}
	}
	xuatdanhsach(ds);
}

void xoanv(danhsach ds, int d)
{
	// int vt = timMSNV(ds, d);
	// if (vt == -1)
	// 	printf("\nkhong tim thay msnv %d muon xoa", d);
	// else
	// 	for (int i = vt; i < ds.n; i++)
	// 	{
	// 		ds.a[i] = ds.a[i + 1];
	// 		ds.n--;
	// 	}
}
