    MemoryProvider p = new MemoryProvider();
            p.addWord("a"); p.addWord("b"); p.addWord("a");
            java.util.List<String> words = p.getWords();
            if (!words.equals(java.util.List.of("a", "b"))) throw new Exception("FAIL");
            System.out.print("PASS");