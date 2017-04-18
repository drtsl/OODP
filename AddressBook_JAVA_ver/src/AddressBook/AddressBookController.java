package AddressBook;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;

import org.json.simple.*;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class AddressBookController implements AddressBookControllerInterface {

	public List<Address> addresslist=new ArrayList<Address>();
	//����
	
	@Override
	public int SearchByName(String name) {
		int index=-1;
		//����Ʈ�� null�ϰ�츦 ����Ͽ�
		int size=addresslist==null ? 0 : addresslist.size();
		for(int i=0;i < size;i++){
			if(addresslist.get(i).getName().equals(name)){
				//���������� �Ұ����ϰ� �߱� ������ �̸��� ������ �ش� �ε����� ��ȯ
				index=i;
			}
		}
		if(index!=-1) return index;
		return -1;
	}

	@Override
	public int SearchByphone(String Phone) {
		//��� 4�ڸ����ڸ� �˻��� �±׷� �����ϰ� �˻��ϴµ�, �ߺ��� ���� �� �����Ƿ� ����Ʈ�� �˻������ �ε����� ��´�. �±װ� ���� ��ȣ���� ����Ʈ���� ��ü ��ȣ�� ���ؼ� ��󳽴�.
		
		//���ڰ� �ƴϸ� -1����
		if(!is_only_digit(Phone)) return -1;
		//�˻�������� ����Ʈ
		List<Address> searchresult=new ArrayList<Address>();
		//�˻�������� �ε����� ����Ʈ
		List<Integer> index=new ArrayList<Integer>();
		String tag;
		//���� ��ȭ��ȣ�� 7���� ���Ϸ� ���� ��ģ���� ���� ��츦 ����� 7�ڸ� �����ϰ�� ��ȭ��ȣ ��ü�� �±װ� �ȴ�.
		if(Phone.length()<7) tag=Phone;
		//�������� ����� ��� 4�ڸ��� �±װ� ��
		else tag=Phone.substring(3, 7);
		//addresslist ����� 0�� ��츦 ���
		int size=addresslist==null ? 0 : addresslist.size();
		
		for(int i=0;i<size;i++){
			if(addresslist.get(i).getTag().equals(tag)){
				//�˻������ �ε����� address�� ���� ����Ʈ�� ��´�
				index.add(i);
				searchresult.add(addresslist.get(i));
			}
		}
		//�˻���� ����Ʈ�� ����� 1�̶�� �� �ش� �˻��±׿� ��ġ�ϴ� ��ȣ�� �ϳ����̶�� �Ҹ��ϱ� �ٷ� ����
		if(searchresult.size()==1) return index.get(0);
		//�ش� �˻��±׿� ��ġ�ϴ� ��ȣ�� �ΰ� �̻� �־ ��ü ���ڸ� ��
		else{
			for(int t=0;t<searchresult.size();t++){
				if(searchresult.get(t).getPhone().equals(Phone)) return index.get(t);
			}
		}
		//������ -1 ������ ��
		return -1;
	}

	@Override
	public void delete(int index) {
		addresslist.remove(index);
		// �ȵǸ� iterator�� �ٲ۴�
	}

	@Override
	public void add(String name, String phone, boolean favorite) {
		// TODO Auto-generated method stub
		//�������� �Ÿ���
		if(SearchByName(name)!=-1){
			System.out.println("That name is already exists");
			return;
		}
		//���� ��ȭ��ȣ �Ÿ���
		if(SearchByphone(phone)!=-1){
			System.out.println("That phone number is already exists");
			return;
		}
		//���ڰ� �ƴ� ��ȭ��ȣ �Ÿ���
		if(!is_only_digit(phone)){
			System.out.println("Only integer in phone number!");
			return;
		}
		Address ad=new Address(name, phone, favorite);
		addresslist.add(ad);
		sort();
	}
	public void edit(int index){
		Scanner sc=new Scanner(System.in);
		String text;
		while(true){
			/*
			 * 
			 * 1. �̸� : ������
			 * 2. ��ȣ : 12456
			 * 3. ��ã : �״Ͽ�
			 * ������ �� ���ÿ�
			 * 1.�̸� 2.��ȣ 3.��ã 4.�ڷΰ���
			 * 
			 */
			 
			System.out.println("1. Name : "+addresslist.get(index).getName());
			System.out.println("2. Phone : "+addresslist.get(index).getPhone());
			String like="false";
			if(addresslist.get(index).isFavorite()) like="true";
			System.out.println("3. Favorite : "+like);
			System.out.println("What do you want to change?");
			System.out.println("1.Name   2.Phone   3.Favorite   4.back");
			String command=sc.nextLine();
			if(command.equals("1") || command.equals("Name") || command.equals("name") || command.equals("NAME")){
				text=sc.nextLine();
				//�������� �Ÿ���
				if(SearchByName(text)!=-1){
					System.out.println("That name is already exists");
					continue;
				}
				addresslist.get(index).setName(text);
			}
			else if(command.equals("2") || command.equals("Phone") || command.equals("phone") || command.equals("PHONE")){
				text=sc.nextLine();
				//���� ��ȣ �Ÿ���
				if(SearchByphone(text)!=-1){
					System.out.println("That phone number is already exists");
					continue;
				}
				//���ڰ� �ƴ� ��ȣ �Ÿ���
				if(!is_only_digit(text)){
					System.out.println("Only integer in phone number!");
					continue;
				}
				addresslist.get(index).setPhone(text);
			}
			else if(command.equals("3") || command.equals("Favorite") || command.equals("favorite") || command.equals("FAVORITE")){
				//���ã������� ���
				if(addresslist.get(index).isFavorite()){
					//��ã ��Ȱ��ȭ�� ���´�
					System.out.println("disable favorite?  (y/n)");
					while(true){
						//yn �ƴϸ� �ȹ޾ƿ�
						text=sc.nextLine();
						if(text.equals("y")){
							addresslist.get(index).setFavorite(false);
							break;
						}
						else if(text.equals("n")){
							break;
						}
					}
				}
				//���ã�� ���°� �ƴҰ��
				else{
					//��ã Ȱ��ȭ�� ���´�
					System.out.println("set to favorite?  (y/n)");
					while(true){
						text=sc.nextLine();
						//��ǻ� ����������
						if(text.equals("y")){
							addresslist.get(index).setFavorite(true);
							break;
						}
						else if(text.equals("n")){
							break;
						}
					}
				}
			}
			else if(command.equals("4") || command.equals("back") || command.equals("Back") || command.equals("BACK")){
				break;
			}
		}
		sort();
	}
	
	@Override
	public void print() {
		// TODO Auto-generated method stub
		//���� ���ã��� �� ������ ������ ����
		/*
		 * 
		 * �� ���ã��
		 * 1. ����
		 * 2. �ȳ�
		 * -------
		 * 1.����
		 * 2.�ƴ�
		 * 3.�ȳ�
		 * 4.����
		 * 
		 */
		
		int size=addresslist.size();
		int favoritecount=1;
		System.out.println("Your favorite\n");
		for(int i=0;i<size;i++){
			if(addresslist.get(i).isFavorite())
			System.out.println(favoritecount+". "+addresslist.get(i).getName());
			favoritecount++;
		}
		System.out.println("--------------");
		
		for(int i=0;i<size;i++){
			System.out.println((i+1)+". "+addresslist.get(i).getName());
		}
		System.out.print("\n");
	}

	@Override
	public void save() {
		// TODO Auto-generated method stub
		//��ü json object�� ���� ����
		JSONObject jsonObject=new JSONObject();
		//array���·� �����ϱ� ���� ����
		JSONArray addressArray=new JSONArray();
		//address�� ������ json���·� ��ȯ��Ű�� ���� ����
		JSONObject addressinfo=new JSONObject();
		//addresslist==null�� ��츦 ���
		int size=addresslist==null ? 0:addresslist.size();
		try{
			for(int i=0;i<size;i++){
				//i��° address�� ������
				Address add=addresslist.get(i);
				//�ʱ�ȭ
				addressinfo=new JSONObject();
				//name ����
				addressinfo.put("name", add.getName());
				//phone ����
				addressinfo.put("phone", add.getPhone());
				//favorite ����. string���·� ������
				if(add.isFavorite()) addressinfo.put("favorite", "true");
				else addressinfo.put("favorite", "false");
				//array���·� json������ ����
				addressArray.add(addressinfo);
			}
		}catch(NullPointerException n){
			n.printStackTrace();
		}
		//������ ���� arrayjson�� ������
		jsonObject.put("Address", addressArray);
		//json�� string���� ��ȯ
		String jsoninfo=jsonObject.toJSONString();
		//json���� �ۼ�
		try{
			FileWriter file=new FileWriter("D:\\temp\\address.json");
			file.write(jsoninfo);
			file.flush();
			file.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}

	@Override
	public void load() {
		// TODO Auto-generated method stub
		//json parser ��ü ����
		JSONParser parser=new JSONParser();
		try{
			//���� ��
			Object obj=parser.parse(new FileReader("D:\\temp\\address.json"));
			JSONObject jsonobject=(JSONObject) obj;
			addresslist=new ArrayList<Address>();
			//address �� json�� ������
			//address�� �迭 ���·� ������ֱ� ������ json array�� �������
			JSONArray arr=(JSONArray) jsonobject.get("Address");
			//����ó��
			if(arr!=null){
				int size=arr.size();
				for(int i=0;i<size;i++){
					//json array���� i��° json object�� �̾ƿ�
					JSONObject jo=(JSONObject) arr.get(i);
					//�̸� ��ȣ ��ã �̾ƿ�
					String name=(String) jo.get("name");
					String phone=(String) jo.get("phone");
					String favorite=(String) jo.get("favorite");
					boolean like=false;
					if(favorite.equals("true")) like=true;
					//�޸𸮿� ����
					add(name, phone, like);
				}
			}
			
		}
		catch(FileNotFoundException fnf){
			fnf.printStackTrace();
		}catch(IOException io){
			io.printStackTrace();
		}catch(ParseException pe){
			pe.printStackTrace();
		}
		sort();
	}

	@Override
	public void sort() {
		// TODO Auto-generated method stub
		//���۰˻���
		Collections.sort(addresslist, new sort());
	}

	boolean is_only_digit(String to_check_) {
		if(Pattern.matches("[a-zA-Z]+", to_check_)==false){
			return true;
		}
		return false;
	}
	
}

class sort implements Comparator<Address>{
	@Override
	public int compare(Address left, Address right){
		return left.getName().compareTo(right.getName());
	}
}
