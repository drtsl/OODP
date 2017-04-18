package SMS;

import java.util.List;

public interface SMSControllerInterface {
	
	public void add(String phone, String text, boolean send);
	public void delete(int index);
	public void print();
	public void save();
	public void load();
}
