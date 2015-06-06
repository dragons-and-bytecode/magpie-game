Feature: A simple Datastore, that gives further context to a function's
         Invocation, allowing the function to hold related data, without
         polluting the context argumnets.

Scenario: Write to a context

    Given the context_store is initialized
      And I know the context_id for my argument data
      And my context is empty
     When I store a value at a specific key to my context
     Then my context should contain a single entry


Scenario: Read from a context

    Given the context_store is initialized
      And I know the context_id for my argument data
      And an entry is stored at a specific key in my context
     When I read that key from my context
     Then I should get the stored value


Scenario: Read default value from non existing keys

    Given the context_store is initialized
      And I know the context_id for my argument data
      And no entry is stored in the context for a specific key
     When I read that key from my context
     Then I should get the default value


Scenario: Remove a value from context

    Given the context_store is initialized
      And I know the context_id for my argument data
      And an entry is stored at a specific key in my context
     When I remove that key from the context
      And I read that key from my context
     Then I should get the default value
