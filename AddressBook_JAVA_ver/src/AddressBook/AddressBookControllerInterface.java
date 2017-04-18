package AddressBook;

public interface AddressBookControllerInterface {

	public int SearchByName(String name);
	public int SearchByphone(String Phone);
	public void delete(int index);
	public void add(String name, String phone, boolean favorite);
	public void edit(int index);
	public void print();
	public void save();
	public void load();
	void sort();
}
