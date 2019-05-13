#ifndef  ICT_CONTACT_H__
#define ICT_CONTACT_H__

namespace sict {


	class Contact
	{
	public:
		Contact();
		Contact(const char *name, const long long phoneNumber[], const int NoOfPhoneNumbersInArray);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool modulus(long long phoneNumber);

	private:
		char m_name[20];
		long long  *m_number;
		int m_size;
	};
}
#endif // ! ICT_CONTACT_H__
