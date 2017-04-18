package AddressBook;




public class Address {
	String name;
	String phone;
	String tag;
	boolean favorite=false;
	
	//생성자
	public Address(String name, String phone, boolean favorite){
		this.name=name;
		this.phone=phone;
		this.favorite=favorite;
		tag=phone.substring(3, 7);
	}
	//이 address의 정보를 모두 보여줌
	public void display(){
		System.out.println("--------------");
		System.out.println("Name : "+name);
		System.out.println("Phone : "+phone);
		String like="no";
		if(favorite) like= "yes";
		System.out.println("Favorite : "+like);
		System.out.println("--------------");
	}
	
	public String getTag() {
		return tag;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public boolean isFavorite() {
		return favorite;
	}

	public void setFavorite(boolean favorite) {
		this.favorite = favorite;
	}
	
	

	
}
