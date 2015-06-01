Feature: A simple Datastore, that gives further context to a function's
         Invocation, allowing the function to hold related data, without
         polluting the context argumnets.

Scenario: Write to a context

    Given the context_store is initialized
      And I know the context_key for my argument data
      And my context is initally empty
     When I store the value <value> at <key> to my context_key
     Then my context should contain a single entry


Scenario: Read from a context

    Given the context_store is initialized
      And I know the context_key for my argument data
      And the entry <key>|<value> is stored in my context
     When I read the key <key> from my context
     Then I should get the value <value>
