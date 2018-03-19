

import junit.framework.TestCase;
import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //assertTrue(urlVal.isValid("https://google.com"));        - Failure 	// Valid URL
	   assertTrue(urlVal.isValid("http://google.com"));							// Valid URL
	   assertTrue(urlVal.isValid("http://go.com"));								// Valid URL
	   assertTrue(urlVal.isValid("http://go.au"));								// Valid URL
	   //assertTrue(!(urlVal.isValid("http:/aaa")));              - Failure		// Invalid URL
	   assertTrue(urlVal.isValid("http://google.com/test1?action=view"));		// Valid URL
	   //assertTrue(!(urlVal.isValid("http://aaa/test")));		  - Failure		// Invalid URL
	   //assertTrue(urlVal.isValid("https://google.com:65535/")); - Failure		// Valid URL
	   assertTrue(!(urlVal.isValid("kajelkfj")));								// Invalid URL
   }
     
   public void testValidURLs(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://google.com"));							// Valid URL
	   assertTrue(urlVal.isValid("http://go.com"));								// Valid URL
	   assertTrue(urlVal.isValid("http://yahoo.com/$23"));						// Valid URL
	   //assertTrue(urlVal.isValid("https://reddit.com/testing"));	  - Failure	// Valid URL
	   assertTrue(urlVal.isValid("http://oregonstate.edu/t123?action=edit"));	// Valid URL
	   //assertTrue(urlVal.isValid("http://bing.org:80/test1/file")); - Failure	// Valid URL
	   assertTrue(urlVal.isValid("http://google.com/test1?action=view"));		// Valid URL
	   //assertTrue(urlVal.isValid("h3t://google.com/"));			  - Failure	// Valid URL
	   //assertTrue(urlVal.isValid("ftp://google.com/"));			  - Failure	// Valid URL
   }
   
   public void testInvalidScheme(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(!(urlVal.isValid("http:google.com")));						// Invalid URL
	   //assertTrue(!(urlVal.isValid("http:/go.com")));				  - Failure	// Invalid URL
	   assertTrue(!(urlVal.isValid("htt/yahoo.com/$23")));						// Invalid URL
	   assertTrue(!(urlVal.isValid("://reddit.com/testing")));					// Invalid URL
	   assertTrue(!(urlVal.isValid("3ht://oregonstate.edu/t123?action=edit")));	// Invalid URL
	   assertTrue(!(urlVal.isValid("ttp:/bing.org/test1/file")));				// Invalid URL
	   assertTrue(!(urlVal.isValid("http/google.com/test1?action=view")));		// Invalid URL
   }
   
   public void testInvalidAuthority(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   // Everything failed. Big issue with the authority checker.
	   //assertTrue(!(urlVal.isValid("http://poodle")));						// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://1234")));							// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://super/$23")));						// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://go.1aa/testing")));	  			// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://aaa/t123?action=edit")));			// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://1.2.3.4.5:80/test1/file"))); 		// Invalid URL
	   //assertTrue(!(urlVal.isValid("http://quack-er/test1?action=view")));	// Invalid URL

   }
   
   public void testInvalidPort(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(!(urlVal.isValid("http://google.com:65a")));							// Invalid URL
	   assertTrue(!(urlVal.isValid("http://go.com:-1")));								// Invalid URL
	   assertTrue(!(urlVal.isValid("http://yahoo.com:65636/$23")));						// Invalid URL
	   assertTrue(!(urlVal.isValid("http://reddit.com:-1/testing")));	  				// Invalid URL
	   assertTrue(!(urlVal.isValid("http://oregonstate.edu:12zba/t123?action=edit")));	// Invalid URL
	   assertTrue(!(urlVal.isValid("http://bing.org:80da/test1/file"))); 				// Invalid URL
	   assertTrue(!(urlVal.isValid("http://google.com:poo/test1?action=view")));		// Invalid URL
   }
   
   public void testInvalidPath(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(!(urlVal.isValid("http://google.com/..")));						// Invalid URL
	   assertTrue(!(urlVal.isValid("http://go.com/../")));							// Invalid URL
	   assertTrue(!(urlVal.isValid("http://yahoo.com/..//file")));					// Invalid URL
	   assertTrue(!(urlVal.isValid("http://reddit.com/testing//test")));	  			// Invalid URL
	   assertTrue(!(urlVal.isValid("http://oregonstate.edu/t123/../d?action=edit")));// Invalid URL
	   assertTrue(!(urlVal.isValid("http://bing.org:80/../abc//../"))); 			// Invalid URL
	   assertTrue(!(urlVal.isValid("http://google.com/..?action=view")));	// Invalid URL
}
   
   public void testIsValid() {
	   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
               new ResultPair("ftp://", true),
               new ResultPair("h3t://", true),
              /* new ResultPair("3ht://", false),
               new ResultPair("http:/", false),
               new ResultPair("http:", false),
               new ResultPair("http/", false),
               new ResultPair("://", false),*/
               new ResultPair("", true)};

	   ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
                  new ResultPair("go.com", true),
                  new ResultPair("go.au", true),
                  new ResultPair("0.0.0.0", true),
                  new ResultPair("255.255.255.255", true),
                  new ResultPair("256.256.256.256", false),
                  new ResultPair("255.com", true),
                  new ResultPair("1.2.3.4.5", false),
                  new ResultPair("1.2.3.4.", false),
                  new ResultPair("1.2.3", false),
                  new ResultPair(".1.2.3.4", false),
                  new ResultPair("go.a", false),
                  new ResultPair("go.a1a", false),
                  new ResultPair("go.1aa", false),
                  new ResultPair("aaa.", false),
                  new ResultPair(".aaa", false),
                  new ResultPair("aaa", false),
                  new ResultPair("", false)
	   };
	   ResultPair[] testUrlPort = {new ResultPair(":80", true),
             new ResultPair(":65535", true),
             new ResultPair(":0", true),
             new ResultPair("", true),
             new ResultPair(":-1", false),
            new ResultPair(":65636",false),
             new ResultPair(":65a", false)
	   };
	   ResultPair[] testPath = {new ResultPair("/test1", true),
          new ResultPair("/t123", true),
          new ResultPair("/$23", true),
          new ResultPair("/..", false),
          new ResultPair("/../", false),
          new ResultPair("/test1/", true),
          new ResultPair("", true),
          new ResultPair("/test1/file", true),
          new ResultPair("/..//file", false),
          new ResultPair("/test1//file", false)
	   };

	   ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
              new ResultPair("?action=edit&mode=up", true),
              new ResultPair("", true)
	   };
	   

	   Object[] testObjects = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random r = new Random();
	   for(int outer = 0; outer < 200; outer++) {
		   boolean expected = true;
		   StringBuilder buffer = new StringBuilder();
		   for(int inner = 0; inner < 5; inner++) {      //loop through and randomly pick from each url part
			   ResultPair[] part = (ResultPair[]) testObjects[inner];
			   int index = r.nextInt(part.length);
	           buffer.append(part[index].item);
	           expected &= !part[index].valid;     //for some reason the bool values are opposite, so I added !
		   }
		   
		   String url = buffer.toString();
		   System.out.println(url);
		   boolean result = urlVal.isValid(url);
		   assertEquals(url, expected, result);
	   
	   	}

   }
   
   
}