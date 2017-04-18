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
	//변수
	
	@Override
	public int SearchByName(String name) {
		int index=-1;
		//리스트가 null일경우를 대비하여
		int size=addresslist==null ? 0 : addresslist.size();
		for(int i=0;i < size;i++){
			if(addresslist.get(i).getName().equals(name)){
				//동명이인은 불가능하게 했기 때문에 이름이 같으면 해당 인덱스를 반환
				index=i;
			}
		}
		if(index!=-1) return index;
		return -1;
	}

	@Override
	public int SearchByphone(String Phone) {
		//가운데 4자리숫자를 검색용 태그로 지정하고 검색하는데, 중복이 있을 수 있으므로 리스트에 검색결과와 인덱스를 담는다. 태그가 같은 번호들의 리스트에서 전체 번호와 비교해서 골라낸다.
		
		//숫자가 아니면 -1리턴
		if(!is_only_digit(Phone)) return -1;
		//검색결과들의 리스트
		List<Address> searchresult=new ArrayList<Address>();
		//검색결과들의 인덱스의 리스트
		List<Integer> index=new ArrayList<Integer>();
		String tag;
		//만약 전화번호를 7글자 이하로 쓰는 미친놈이 있을 경우를 대비해 7자리 이하일경우 전화번호 전체가 태그가 된다.
		if(Phone.length()<7) tag=Phone;
		//정상적인 경우라면 가운데 4자리가 태그가 됨
		else tag=Phone.substring(3, 7);
		//addresslist 사이즈가 0일 경우를 대비
		int size=addresslist==null ? 0 : addresslist.size();
		
		for(int i=0;i<size;i++){
			if(addresslist.get(i).getTag().equals(tag)){
				//검색결과의 인덱스와 address를 각각 리스트에 담는다
				index.add(i);
				searchresult.add(addresslist.get(i));
			}
		}
		//검색결과 리스트의 사이즈가 1이라는 건 해당 검색태그와 일치하는 번호가 하나뿐이라는 소리니까 바로 리턴
		if(searchresult.size()==1) return index.get(0);
		//해당 검색태그와 일치하는 번호가 두개 이상 있어서 전체 숫자를 비교
		else{
			for(int t=0;t<searchresult.size();t++){
				if(searchresult.get(t).getPhone().equals(Phone)) return index.get(t);
			}
		}
		//없으면 -1 리턴함 ㅎ
		return -1;
	}

	@Override
	public void delete(int index) {
		addresslist.remove(index);
		// 안되면 iterator로 바꾼다
	}

	@Override
	public void add(String name, String phone, boolean favorite) {
		// TODO Auto-generated method stub
		//동명이인 거르기
		if(SearchByName(name)!=-1){
			System.out.println("That name is already exists");
			return;
		}
		//같은 전화번호 거르기
		if(SearchByphone(phone)!=-1){
			System.out.println("That phone number is already exists");
			return;
		}
		//숫자가 아닌 전화번호 거르기
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
			 * 1. 이름 : ㅎㅎㅎ
			 * 2. 번호 : 12456
			 * 3. 즐찾 : 네니요
			 * 수정할 걸 고르시오
			 * 1.이름 2.번호 3.즐찾 4.뒤로가기
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
				//동명이인 거르기
				if(SearchByName(text)!=-1){
					System.out.println("That name is already exists");
					continue;
				}
				addresslist.get(index).setName(text);
			}
			else if(command.equals("2") || command.equals("Phone") || command.equals("phone") || command.equals("PHONE")){
				text=sc.nextLine();
				//같은 번호 거르기
				if(SearchByphone(text)!=-1){
					System.out.println("That phone number is already exists");
					continue;
				}
				//숫자가 아닌 번호 거르기
				if(!is_only_digit(text)){
					System.out.println("Only integer in phone number!");
					continue;
				}
				addresslist.get(index).setPhone(text);
			}
			else if(command.equals("3") || command.equals("Favorite") || command.equals("favorite") || command.equals("FAVORITE")){
				//즐겨찾기상태일 경우
				if(addresslist.get(index).isFavorite()){
					//즐찾 비활성화를 묻는다
					System.out.println("disable favorite?  (y/n)");
					while(true){
						//yn 아니면 안받아요
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
				//즐겨찾기 상태가 아닐경우
				else{
					//즐찾 활성화를 묻는다
					System.out.println("set to favorite?  (y/n)");
					while(true){
						text=sc.nextLine();
						//사실상 이지선다임
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
		//아직 즐겨찾기로 뭘 할지는 정하지 않음
		/*
		 * 
		 * 내 즐겨찾기
		 * 1. 누구
		 * 2. 안녕
		 * -------
		 * 1.누구
		 * 2.아니
		 * 3.안녕
		 * 4.ㄱㄱ
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
		//전체 json object가 들어가는 변수
		JSONObject jsonObject=new JSONObject();
		//array형태로 저장하기 위한 변수
		JSONArray addressArray=new JSONArray();
		//address의 정보를 json형태로 변환시키기 위한 변수
		JSONObject addressinfo=new JSONObject();
		//addresslist==null일 경우를 대비
		int size=addresslist==null ? 0:addresslist.size();
		try{
			for(int i=0;i<size;i++){
				//i번째 address를 가져옴
				Address add=addresslist.get(i);
				//초기화
				addressinfo=new JSONObject();
				//name 저장
				addressinfo.put("name", add.getName());
				//phone 저장
				addressinfo.put("phone", add.getPhone());
				//favorite 저장. string형태로 저장함
				if(add.isFavorite()) addressinfo.put("favorite", "true");
				else addressinfo.put("favorite", "false");
				//array형태로 json파일을 만듬
				addressArray.add(addressinfo);
			}
		}catch(NullPointerException n){
			n.printStackTrace();
		}
		//위에서 모은 arrayjson을 저장함
		jsonObject.put("Address", addressArray);
		//json을 string으로 변환
		String jsoninfo=jsonObject.toJSONString();
		//json파일 작성
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
		//json parser 객체 생성
		JSONParser parser=new JSONParser();
		try{
			//파일 염
			Object obj=parser.parse(new FileReader("D:\\temp\\address.json"));
			JSONObject jsonobject=(JSONObject) obj;
			addresslist=new ArrayList<Address>();
			//address 내 json을 가져옴
			//address는 배열 형태로 저장되있기 때문에 json array에 집어넣음
			JSONArray arr=(JSONArray) jsonobject.get("Address");
			//오류처리
			if(arr!=null){
				int size=arr.size();
				for(int i=0;i<size;i++){
					//json array에서 i번째 json object를 뽑아옴
					JSONObject jo=(JSONObject) arr.get(i);
					//이름 번호 즐찾 뽑아옴
					String name=(String) jo.get("name");
					String phone=(String) jo.get("phone");
					String favorite=(String) jo.get("favorite");
					boolean like=false;
					if(favorite.equals("true")) like=true;
					//메모리에 저장
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
		//구글검색함
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
