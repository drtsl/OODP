package Call;

import java.util.List;

public interface CallControllerInterface {
	
	public void add(String phone, String time, boolean send);
	public void delete(int index);
	public void print();
	public void save();
	public void load();
}
