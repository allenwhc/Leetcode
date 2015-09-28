
public class Trie {
	public static class TrieNode{
		int val;
		TrieNode[] children=new TrieNode[26];
		public TrieNode() {
			this.val=0;
			for(int i=0; i<26; i++)
				children[i]=null;
		}
	}
	
	private static TrieNode root;
	private static int count;
	public Trie() {
		// TODO Auto-generated constructor stub
		root=new TrieNode();
		count=0;
	}
	
	// Inserts a word into the trie.
    public static void insert(String word) {
        TrieNode node=root;
        for(int i=0; i<word.length(); i++){
        	int letterASCII=word.charAt(i)-'a';
        	if(node.children[letterASCII]==null)
        		node.children[letterASCII]=new TrieNode();
        	node=node.children[letterASCII];
        }
        count++;
        node.val=count;
    }

    // Returns if the word is in the trie.
    public static boolean search(String word) {
        TrieNode node=root;
        for(int i=0; i<word.length(); i++){
        	int letterASCII=word.charAt(i)-'a';
        	if(node.children[letterASCII]!=null)
        		node=node.children[letterASCII];
        	else
        		return false;
        }
        if(node.val!=0) return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public static boolean startsWith(String prefix) {
        TrieNode node=root;
        for(int i=0; i<prefix.length(); i++){
        	int letterASCII=prefix.charAt(i)-'a';
        	if(node.children[letterASCII]!=null)
        		node=node.children[letterASCII];
        	else
        		return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
		Trie trie=new Trie();
		trie.insert("banana");
		trie.insert("apple");
		trie.insert("kiwi");
		System.out.println(trie.search("apple"));
		System.out.println(trie.search("peach"));
		System.out.println(trie.startsWith("ban"));
	}
}
